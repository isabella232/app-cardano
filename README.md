# Cardano Ledger App

Cardano Ledger App for Ledger Nano S


## Building

### Loading the app

`make load`

Builds and loads the application into connected device. Just make sure to close the Ledger app on the device before running the command.


### Debug version

In `Makefile`, uncomment

    #DEVEL = 1
    #DEFINES += HEADLESS

also comment out

    DEFINES += RESET_ON_CRASH

and then run `make clean load`.

### Setup

Make sure you have:
- SDK >= 2.0.0
- MCU >= 1.11

Environment setup and developer documentation is sufficiently provided in Ledger’s [Read the Docs](https://developers.ledger.com/docs/nano-app/quickstart/).

You want a debug version of the MCU firmware (but it blocks SDK firmware updates, so for the purpose of upgrading SDK, replace it temporarily with a non-debug one). Instructions for swapping MCU versions: https://github.com/LedgerHQ/ledger-dev-doc/blob/master/source/userspace/debugging.rst

### Troubleshooting connection problems

The quickstart guide's script sets up your udev rules, but there still might be problems.
- https://support.ledger.com/hc/en-us/articles/115005165269-Fix-connection-issues

## Development

To learn more about development process and individual commands, [check the desing doc](doc/design_doc.md).

## Deploying

The build process is managed with [Make](https://www.gnu.org/software/make/).

### Make Commands

* `load`: Load signed app onto the Ledger device
* `clean`: Clean the build and output directories
* `delete`: Remove the application from the device
* `build`: Build obj and bin api artefacts without loading
* `format`: Format source code.

See `Makefile` for list of included functions.

## How to get a transaction body computed by Ledger

Ledger computes a rolling hash of the serialized transaction body, but the body itself is ordinarily not available. It is possible to acquire it from the development build by going through the following steps:

1. [Install debug MCU](https://developers.ledger.com/docs/nano-app/debug/#introduction) on your Ledger Nano S device.

2. Install the debug version of Cardano app (see above).

3. Install `usbtool` and turn on [console printing](https://developers.ledger.com/docs/nano-app/debug/#console-printing).

4. Send a single `signTx` call to Ledger (e.g. by running `yarn test-integration --grep "<some-signTx-test>"`).

5. After the call is processed, the terminal running console printing now contains all log messages resulting from that `signTx` call. (See the `TRACE*` macros.) Extract the transaction body logs (dumped by the function computing the rolling tx hash; you can identify them by function names following the pattern `blake2b_256_append*tx_body`) and merge them into a single hexstring. You can use the following javascript to achieve it:

```javascript
       const logfile = `<content of the log file>`
       console.log(logfile.split('\n').filter((x) => x.includes('blake2b_256_append'))
           .map((x) => x.split(' ')[1]).join(''))
```

WARNING: the output of tracing sometimes (although very rarely) gets slightly mangled (for instance, the output contains `blake2b_s56_append` instead of `blake2b_256_append`) and then the script above produces an incorrect result.

6. Analyze the obtained output via https://cbor.me. The result of the decoding is close to valid json and can be pretty-printed by https://jsonformatter.curiousconcept.com/ (replacing `h'` with `'` removes the errors).
