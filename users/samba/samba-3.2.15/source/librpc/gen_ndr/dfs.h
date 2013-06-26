/* header auto-generated by pidl */

#include <stdint.h>

#ifndef _HEADER_netdfs
#define _HEADER_netdfs

#define DFS_STORAGE_STATES	( 0xf )
enum dfs_ManagerVersion
#ifndef USE_UINT_ENUMS
 {
	DFS_MANAGER_VERSION_NT4=1,
	DFS_MANAGER_VERSION_W2K=2,
	DFS_MANAGER_VERSION_W2K3=4
}
#else
 { __donnot_use_enum_dfs_ManagerVersion=0x7FFFFFFF}
#define DFS_MANAGER_VERSION_NT4 ( 1 )
#define DFS_MANAGER_VERSION_W2K ( 2 )
#define DFS_MANAGER_VERSION_W2K3 ( 4 )
#endif
;

struct dfs_Info0 {
	char _empty_;
};

struct dfs_Info1 {
	const char *path;/* [unique,charset(UTF16)] */
};

/* bitmap dfs_VolumeState */
#define DFS_VOLUME_STATE_OK ( 0x1 )
#define DFS_VOLUME_STATE_INCONSISTENT ( 0x2 )
#define DFS_VOLUME_STATE_OFFLINE ( 0x3 )
#define DFS_VOLUME_STATE_ONLINE ( 0x4 )
#define DFS_VOLUME_STATE_STANDALONE ( DFS_VOLUME_FLAVOR_STANDALONE )
#define DFS_VOLUME_STATE_AD_BLOB ( DFS_VOLUME_FLAVOR_AD_BLOB )

struct dfs_Info2 {
	const char *path;/* [unique,charset(UTF16)] */
	const char *comment;/* [unique,charset(UTF16)] */
	uint32_t state;
	uint32_t num_stores;
};

/* bitmap dfs_StorageState */
#define DFS_STORAGE_STATE_OFFLINE ( 1 )
#define DFS_STORAGE_STATE_ONLINE ( 2 )
#define DFS_STORAGE_STATE_ACTIVE ( 4 )

struct dfs_StorageInfo {
	uint32_t state;
	const char *server;/* [unique,charset(UTF16)] */
	const char *share;/* [unique,charset(UTF16)] */
};

struct dfs_Info3 {
	const char *path;/* [unique,charset(UTF16)] */
	const char *comment;/* [unique,charset(UTF16)] */
	uint32_t state;
	uint32_t num_stores;
	struct dfs_StorageInfo *stores;/* [unique,size_is(num_stores)] */
};

struct dfs_Info4 {
	const char *path;/* [unique,charset(UTF16)] */
	const char *comment;/* [unique,charset(UTF16)] */
	uint32_t state;
	uint32_t timeout;
	struct GUID guid;
	uint32_t num_stores;
	struct dfs_StorageInfo *stores;/* [unique,size_is(num_stores)] */
};

/* bitmap dfs_PropertyFlags */
#define DFS_PROPERTY_FLAG_INSITE_REFERRALS ( 0x01 )
#define DFS_PROPERTY_FLAG_ROOT_SCALABILITY ( 0x02 )
#define DFS_PROPERTY_FLAG_SITE_COSTING ( 0x04 )
#define DFS_PROPERTY_FLAG_TARGET_FAILBACK ( 0x08 )
#define DFS_PROPERTY_FLAG_CLUSTER_ENABLED ( 0x10 )

struct dfs_Info5 {
	const char *path;/* [unique,charset(UTF16)] */
	const char *comment;/* [unique,charset(UTF16)] */
	uint32_t state;
	uint32_t timeout;
	struct GUID guid;
	uint32_t flags;
	uint32_t pktsize;
	uint32_t num_stores;
};

enum dfs_Target_PriorityClass
#ifndef USE_UINT_ENUMS
 {
	DFS_INVALID_PRIORITY_CLASS=-1,
	DFS_SITE_COST_NORMAL_PRIORITY_CLASS=0,
	DFS_GLOBAL_HIGH_PRIORITY_CLASS=1,
	DFS_SITE_COST_HIGH_PRIORITY_CLASS=2,
	DFS_SITE_COST_LOW_PRIORITY_CLASS=3,
	DFS_GLOBAL_LOW_PRIORITY_CLASS=4
}
#else
 { __donnot_use_enum_dfs_Target_PriorityClass=0x7FFFFFFF}
#define DFS_INVALID_PRIORITY_CLASS ( -1 )
#define DFS_SITE_COST_NORMAL_PRIORITY_CLASS ( 0 )
#define DFS_GLOBAL_HIGH_PRIORITY_CLASS ( 1 )
#define DFS_SITE_COST_HIGH_PRIORITY_CLASS ( 2 )
#define DFS_SITE_COST_LOW_PRIORITY_CLASS ( 3 )
#define DFS_GLOBAL_LOW_PRIORITY_CLASS ( 4 )
#endif
;

struct dfs_Target_Priority {
	enum dfs_Target_PriorityClass target_priority_class;
	uint16_t target_priority_rank;
	uint16_t reserved;
};

struct dfs_StorageInfo2 {
	struct dfs_StorageInfo info;
	struct dfs_Target_Priority target_priority;
};

struct dfs_Info6 {
	const char *entry_path;/* [unique,charset(UTF16)] */
	const char *comment;/* [unique,charset(UTF16)] */
	uint32_t state;
	uint32_t timeout;
	struct GUID guid;
	uint32_t flags;
	uint32_t pktsize;
	uint16_t num_stores;
	struct dfs_StorageInfo2 *stores;/* [unique,size_is(num_stores)] */
};

struct dfs_Info7 {
	struct GUID generation_guid;
};

struct dfs_Info100 {
	const char *comment;/* [unique,charset(UTF16)] */
};

struct dfs_Info101 {
	uint32_t state;
};

struct dfs_Info102 {
	uint32_t timeout;
};

struct dfs_Info103 {
	uint32_t flags;
};

struct dfs_Info104 {
	struct dfs_Target_Priority priority;
};

struct dfs_Info105 {
	const char *comment;/* [unique,charset(UTF16)] */
	uint32_t state;
	uint32_t timeout;
	uint32_t property_flag_mask;
	uint32_t property_flags;
};

struct dfs_Info106 {
	uint32_t state;
	struct dfs_Target_Priority priority;
};

struct dfs_Info200 {
	const char *dom_root;/* [unique,charset(UTF16)] */
};

enum dfs_VolumeFlavor
#ifndef USE_UINT_ENUMS
 {
	DFS_VOLUME_FLAVOR_STANDALONE=0x100,
	DFS_VOLUME_FLAVOR_AD_BLOB=0x200
}
#else
 { __donnot_use_enum_dfs_VolumeFlavor=0x7FFFFFFF}
#define DFS_VOLUME_FLAVOR_STANDALONE ( 0x100 )
#define DFS_VOLUME_FLAVOR_AD_BLOB ( 0x200 )
#endif
;

struct dfs_Info300 {
	enum dfs_VolumeFlavor flavor;
	const char *dom_root;/* [unique,charset(UTF16)] */
};

union dfs_Info {
	struct dfs_Info0 *info0;/* [unique,case(0)] */
	struct dfs_Info1 *info1;/* [unique,case] */
	struct dfs_Info2 *info2;/* [unique,case(2)] */
	struct dfs_Info3 *info3;/* [unique,case(3)] */
	struct dfs_Info4 *info4;/* [unique,case(4)] */
	struct dfs_Info5 *info5;/* [unique,case(5)] */
	struct dfs_Info6 *info6;/* [unique,case(6)] */
	struct dfs_Info7 *info7;/* [unique,case(7)] */
	struct dfs_Info100 *info100;/* [unique,case(100)] */
	struct dfs_Info101 *info101;/* [unique,case(101)] */
	struct dfs_Info102 *info102;/* [unique,case(102)] */
	struct dfs_Info103 *info103;/* [unique,case(103)] */
	struct dfs_Info104 *info104;/* [unique,case(104)] */
	struct dfs_Info105 *info105;/* [unique,case(105)] */
	struct dfs_Info106 *info106;/* [unique,case(106)] */
};

struct dfs_EnumArray1 {
	uint32_t count;
	struct dfs_Info1 *s;/* [unique,size_is(count)] */
};

struct dfs_EnumArray2 {
	uint32_t count;
	struct dfs_Info2 *s;/* [unique,size_is(count)] */
};

struct dfs_EnumArray3 {
	uint32_t count;
	struct dfs_Info3 *s;/* [unique,size_is(count)] */
};

struct dfs_EnumArray4 {
	uint32_t count;
	struct dfs_Info4 *s;/* [unique,size_is(count)] */
};

struct dfs_EnumArray5 {
	uint32_t count;
	struct dfs_Info5 *s;/* [unique,size_is(count)] */
};

struct dfs_EnumArray6 {
	uint32_t count;
	struct dfs_Info6 *s;/* [unique,size_is(count)] */
};

struct dfs_EnumArray200 {
	uint32_t count;
	struct dfs_Info200 *s;/* [unique,size_is(count)] */
};

struct dfs_EnumArray300 {
	uint32_t count;
	struct dfs_Info300 *s;/* [unique,size_is(count)] */
};

union dfs_EnumInfo {
	struct dfs_EnumArray1 *info1;/* [unique,case] */
	struct dfs_EnumArray2 *info2;/* [unique,case(2)] */
	struct dfs_EnumArray3 *info3;/* [unique,case(3)] */
	struct dfs_EnumArray4 *info4;/* [unique,case(4)] */
	struct dfs_EnumArray5 *info5;/* [unique,case(5)] */
	struct dfs_EnumArray6 *info6;/* [unique,case(6)] */
	struct dfs_EnumArray200 *info200;/* [unique,case(200)] */
	struct dfs_EnumArray300 *info300;/* [unique,case(300)] */
};

struct dfs_EnumStruct {
	uint32_t level;
	union dfs_EnumInfo e;/* [switch_is(level)] */
};

struct dfs_UnknownStruct {
	uint32_t unknown1;
	const char *unknown2;/* [unique,charset(UTF16)] */
};


struct dfs_GetManagerVersion {
	struct {
		enum dfs_ManagerVersion *version;/* [ref] */
	} out;

};


struct dfs_Add {
	struct {
		const char *path;/* [ref,charset(UTF16)] */
		const char *server;/* [ref,charset(UTF16)] */
		const char *share;/* [unique,charset(UTF16)] */
		const char *comment;/* [unique,charset(UTF16)] */
		uint32_t flags;
	} in;

	struct {
		WERROR result;
	} out;

};


struct dfs_Remove {
	struct {
		const char *dfs_entry_path;/* [ref,charset(UTF16)] */
		const char *servername;/* [unique,charset(UTF16)] */
		const char *sharename;/* [unique,charset(UTF16)] */
	} in;

	struct {
		WERROR result;
	} out;

};


struct dfs_SetInfo {
	struct {
		const char *dfs_entry_path;/* [charset(UTF16)] */
		const char *servername;/* [unique,charset(UTF16)] */
		const char *sharename;/* [unique,charset(UTF16)] */
		uint32_t level;
		union dfs_Info *info;/* [ref,switch_is(level)] */
	} in;

	struct {
		WERROR result;
	} out;

};


struct dfs_GetInfo {
	struct {
		const char *dfs_entry_path;/* [charset(UTF16)] */
		const char *servername;/* [unique,charset(UTF16)] */
		const char *sharename;/* [unique,charset(UTF16)] */
		uint32_t level;
	} in;

	struct {
		union dfs_Info *info;/* [ref,switch_is(level)] */
		WERROR result;
	} out;

};


struct dfs_Enum {
	struct {
		uint32_t level;
		uint32_t bufsize;
		struct dfs_EnumStruct *info;/* [unique] */
		uint32_t *total;/* [unique] */
	} in;

	struct {
		struct dfs_EnumStruct *info;/* [unique] */
		uint32_t *total;/* [unique] */
		WERROR result;
	} out;

};


struct dfs_Rename {
	struct {
		WERROR result;
	} out;

};


struct dfs_Move {
	struct {
		WERROR result;
	} out;

};


struct dfs_ManagerGetConfigInfo {
	struct {
		WERROR result;
	} out;

};


struct dfs_ManagerSendSiteInfo {
	struct {
		WERROR result;
	} out;

};


struct dfs_AddFtRoot {
	struct {
		const char *servername;/* [charset(UTF16)] */
		const char *dns_servername;/* [charset(UTF16)] */
		const char *dfsname;/* [charset(UTF16)] */
		const char *rootshare;/* [charset(UTF16)] */
		const char *comment;/* [charset(UTF16)] */
		const char *dfs_config_dn;/* [charset(UTF16)] */
		uint8_t unknown1;
		uint32_t flags;
		struct dfs_UnknownStruct **unknown2;/* [unique] */
	} in;

	struct {
		struct dfs_UnknownStruct **unknown2;/* [unique] */
		WERROR result;
	} out;

};


struct dfs_RemoveFtRoot {
	struct {
		const char *servername;/* [charset(UTF16)] */
		const char *dns_servername;/* [charset(UTF16)] */
		const char *dfsname;/* [charset(UTF16)] */
		const char *rootshare;/* [charset(UTF16)] */
		uint32_t flags;
		struct dfs_UnknownStruct **unknown;/* [unique] */
	} in;

	struct {
		struct dfs_UnknownStruct **unknown;/* [unique] */
		WERROR result;
	} out;

};


struct dfs_AddStdRoot {
	struct {
		const char *servername;/* [charset(UTF16)] */
		const char *rootshare;/* [charset(UTF16)] */
		const char *comment;/* [charset(UTF16)] */
		uint32_t flags;
	} in;

	struct {
		WERROR result;
	} out;

};


struct dfs_RemoveStdRoot {
	struct {
		const char *servername;/* [charset(UTF16)] */
		const char *rootshare;/* [charset(UTF16)] */
		uint32_t flags;
	} in;

	struct {
		WERROR result;
	} out;

};


struct dfs_ManagerInitialize {
	struct {
		const char *servername;/* [ref,charset(UTF16)] */
		uint32_t flags;
	} in;

	struct {
		WERROR result;
	} out;

};


struct dfs_AddStdRootForced {
	struct {
		const char *servername;/* [charset(UTF16)] */
		const char *rootshare;/* [charset(UTF16)] */
		const char *comment;/* [charset(UTF16)] */
		const char *store;/* [charset(UTF16)] */
	} in;

	struct {
		WERROR result;
	} out;

};


struct dfs_GetDcAddress {
	struct {
		const char *servername;/* [charset(UTF16)] */
		const char **server_fullname;/* [ref,charset(UTF16)] */
		uint8_t *is_root;/* [ref] */
		uint32_t *ttl;/* [ref] */
	} in;

	struct {
		const char **server_fullname;/* [ref,charset(UTF16)] */
		uint8_t *is_root;/* [ref] */
		uint32_t *ttl;/* [ref] */
		WERROR result;
	} out;

};


struct dfs_SetDcAddress {
	struct {
		const char *servername;/* [charset(UTF16)] */
		const char *server_fullname;/* [charset(UTF16)] */
		uint32_t flags;
		uint32_t ttl;
	} in;

	struct {
		WERROR result;
	} out;

};


struct dfs_FlushFtTable {
	struct {
		const char *servername;/* [charset(UTF16)] */
		const char *rootshare;/* [charset(UTF16)] */
	} in;

	struct {
		WERROR result;
	} out;

};


struct dfs_Add2 {
	struct {
		WERROR result;
	} out;

};


struct dfs_Remove2 {
	struct {
		WERROR result;
	} out;

};


struct dfs_EnumEx {
	struct {
		const char *dfs_name;/* [charset(UTF16)] */
		uint32_t level;
		uint32_t bufsize;
		struct dfs_EnumStruct *info;/* [unique] */
		uint32_t *total;/* [unique] */
	} in;

	struct {
		struct dfs_EnumStruct *info;/* [unique] */
		uint32_t *total;/* [unique] */
		WERROR result;
	} out;

};


struct dfs_SetInfo2 {
	struct {
		WERROR result;
	} out;

};

#endif /* _HEADER_netdfs */