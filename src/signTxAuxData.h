#ifndef H_CARDANO_APP_SIGN_TX_AUX_DATA
#define H_CARDANO_APP_SIGN_TX_AUX_DATA

typedef enum {
	AUX_DATA_TYPE_ARBITRARY_HASH = 0,
	AUX_DATA_TYPE_CATALYST_VOTING_KEY_REGISTRATION = 1,
} aux_data_type_t;

#endif // H_CARDANO_APP_SIGN_TX_AUX_DATA