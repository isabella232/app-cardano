#ifndef H_CARDANO_APP_SECURITY_POLICY
#define H_CARDANO_APP_SECURITY_POLICY

#include "addressUtilsShelley.h"
#include "bip44.h"
#include "cardano.h"
#include "securityPolicyType.h"
#include "signTxPoolRegistration.h"
#include "signTxAuxData.h"
#include "signTx.h"

bool is_tx_network_verifiable(
        sign_tx_signingmode_t txSigningMode,
        uint16_t numOutputs,
        uint16_t numWithdrawals
);

security_policy_t policyForDerivePrivateKey(const bip44_path_t* path);

security_policy_t policyForGetPublicKeysInit(size_t numPaths);
security_policy_t policyForGetExtendedPublicKey(const bip44_path_t* pathSpec);
security_policy_t policyForGetExtendedPublicKeyBulkExport(const bip44_path_t* pathSpec);

security_policy_t policyForShowDeriveAddress(const addressParams_t* addressParams);
security_policy_t policyForReturnDeriveAddress(const addressParams_t* addressParams);


security_policy_t policyForSignTxInit(
        sign_tx_signingmode_t txSigningMode,
        uint8_t networkId,
        uint32_t protocolMagic,
        uint16_t numInputs,
        uint16_t numOutputs,
        uint16_t numCertificates,
        uint16_t numWithdrawals,
        bool includeMint
);

security_policy_t policyForSignTxInput();

security_policy_t policyForSignTxOutputAddressBytes(
        sign_tx_signingmode_t txSigningMode,
        const uint8_t* rawAddressBuffer, size_t rawAddressSize,
        const uint8_t networkId, const uint32_t protocolMagic
);
security_policy_t policyForSignTxOutputAddressParams(
        sign_tx_signingmode_t txSigningMode,
        const addressParams_t* params,
        const uint8_t networkId, const uint32_t protocolMagic
);
security_policy_t policyForSignTxOutputConfirm(
        security_policy_t addressPolicy,
        uint64_t numAssetGroups
);

security_policy_t policyForSignTxFee(sign_tx_signingmode_t txSigningMode, uint64_t fee);

security_policy_t policyForSignTxTtl(uint32_t ttl);

security_policy_t policyForSignTxCertificate(
        sign_tx_signingmode_t txSigningMode,
        const certificate_type_t certificateType
);
security_policy_t policyForSignTxCertificateStaking(
        sign_tx_signingmode_t txSigningMode,
        const certificate_type_t certificateType,
        const stake_credential_t* stakeCredential
);
security_policy_t policyForSignTxCertificateStakePoolRetirement(
        sign_tx_signingmode_t txSigningMode,
        const bip44_path_t* stakeCredential,
        uint64_t epoch
);
security_policy_t policyForSignTxStakePoolRegistrationPoolId(
        sign_tx_signingmode_t txSigningMode,
        const pool_id_t* poolId
);
security_policy_t policyForSignTxStakePoolRegistrationVrfKey(
        sign_tx_signingmode_t txSigningMode
);
security_policy_t policyForSignTxStakePoolRegistrationRewardAccount(
        sign_tx_signingmode_t txSigningMode,
        const reward_account_t* poolRewardAccount
);
security_policy_t policyForSignTxStakePoolRegistrationOwner(
        const sign_tx_signingmode_t txSigningMode,
        const pool_owner_t* owner
);
security_policy_t policyForSignTxStakePoolRegistrationRelay(
        const sign_tx_signingmode_t txSigningMode,
        const pool_relay_t* relay
);
security_policy_t policyForSignTxStakePoolRegistrationMetadata();
security_policy_t policyForSignTxStakePoolRegistrationNoMetadata();
security_policy_t policyForSignTxStakePoolRegistrationConfirm(
        uint32_t numOwners, uint32_t numRelays
);

security_policy_t policyForSignTxWithdrawal(
        sign_tx_signingmode_t txSigningMode,
        const stake_credential_t* stakeCredential
);

security_policy_t policyForSignTxAuxData(aux_data_type_t auxDataType);

security_policy_t policyForSignTxValidityIntervalStart();

security_policy_t policyForSignTxMintInit(const sign_tx_signingmode_t txSigningMode);
security_policy_t policyForSignTxMintConfirm(security_policy_t outputPolicy);

security_policy_t policyForSignTxWitness(
        sign_tx_signingmode_t txSigningMode,
        const bip44_path_t* pathSpec,
        bool mintPresent
);

security_policy_t policyForSignTxConfirm();

security_policy_t policyForSignOpCert(const bip44_path_t* poolColdKeyPathSpec);

security_policy_t policyForCatalystRegistrationVotingRewardsAddressParams(
        const addressParams_t* params,
        const uint8_t networkId
);
security_policy_t policyForCatalystRegistrationStakingKey(
        const bip44_path_t* stakingKeyPath
);
security_policy_t policyForCatalystRegistrationVotingKey();
security_policy_t policyForCatalystRegistrationNonce();
security_policy_t policyForCatalystRegistrationConfirm();

#endif // H_CARDANO_APP_SECURITY_POLICY
