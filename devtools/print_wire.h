#ifndef LIGHTNING_DEVTOOLS_PRINT_WIRE_H
#define LIGHTNING_DEVTOOLS_PRINT_WIRE_H
#include "config.h"
#include <brocoin/preimage.h>
#include <brocoin/tx.h>
#include <common/wireaddr.h>
#include <wire/peer_wire.h>
#include <wire/onion_wire.h>

struct tlv_print_record_type {
	u64 type;
	bool (*print)(const char *tlv_name, const u8 **cursor, size_t *plen);
};

typedef u64 bigsize;
#define printwire_bigsize printwire_u64
struct wireaddr;

bool printwire_u8(const char *fieldname, const u8 **cursor, size_t *plen);
bool printwire_u16(const char *fieldname, const u8 **cursor, size_t *plen);
bool printwire_u32(const char *fieldname, const u8 **cursor, size_t *plen);
bool printwire_u64(const char *fieldname, const u8 **cursor, size_t *plen);
bool printwire_tu16(const char *fieldname, const u8 **cursor, size_t *plen);
bool printwire_tu32(const char *fieldname, const u8 **cursor, size_t *plen);
bool printwire_tu64(const char *fieldname, const u8 **cursor, size_t *plen);
bool printwire_u8_array(const char *fieldname, const u8 **cursor, size_t *plen, size_t len);
bool printwire_utf8_array(const char *fieldname, const u8 **cursor, size_t *plen, size_t len);
bool printwire_tlvs(const char *tlv_name, const u8 **cursor, size_t *plen,
		    const struct tlv_print_record_type types[], size_t num_types);

bool printwire_bip340sig(const char *fieldname, const u8 **cursor, size_t *plen);
bool printwire_brocoin_blkid(const char *fieldname, const u8 **cursor, size_t *plen);
bool printwire_wireaddr(const char *fieldname, const u8 **cursor, size_t *plen);
bool printwire_brocoin_txid(const char *fieldname, const u8 **cursor, size_t *plen);
bool printwire_channel_id(const char *fieldname, const u8 **cursor, size_t *plen);
bool printwire_amount_bro(const char *fieldname, const u8 **cursor, size_t *plen);
bool printwire_amount_mbro(const char *fieldname, const u8 **cursor, size_t *plen);
bool printwire_point32(const char *fieldname, const u8 **cursor, size_t *plen);
bool printwire_preimage(const char *fieldname, const u8 **cursor, size_t *plen);
bool printwire_pubkey(const char *fieldname, const u8 **cursor, size_t *plen);
bool printwire_node_id(const char *fieldname, const u8 **cursor, size_t *plen);
bool printwire_secp256k1_ecdsa_signature(const char *fieldname, const u8 **cursor, size_t *plen);
bool printwire_sha256(const char *fieldname, const u8 **cursor, size_t *plen);
bool printwire_secret(const char *fieldname, const u8 **cursor, size_t *plen);
bool printwire_short_channel_id(const char *fieldname, const u8 **cursor, size_t *plen);

#endif /* LIGHTNING_DEVTOOLS_PRINT_WIRE_H */