#ifndef TINYCMDPKT_H
#define TINYCMDPKT_H

#define TINYCMD_LED_MAX               20
#define TINYCMD_THREE_LOCK_NUM        3
#define TINYCMD_TEST_DATA_LEN         (TINYCMD_LED_MAX * 3 + TINYCMD_THREE_LOCK_NUM)

enum {
  TINY_RESET_HARD = 0,
  TINY_RESET_SOFT,
  TINY_RESET_DATA,
  TINY_RESET_MAX
} reset_type_e;

typedef struct
{
  uint8_t g;
  uint8_t r;
  uint8_t b;
} tinycmd_led_type;

typedef struct
{
  uint8_t cmd_code;
  uint8_t pkt_len;
  uint8_t rgb_num;
  uint8_t rgb_preset_index;
  uint8_t led_preset_num;
  uint8_t led_preset_index;
} tinycmd_config_req_type;

typedef struct
{
  uint8_t cmd_code;
  uint8_t pkt_len;
} tinycmd_ver_req_type;

typedef struct
{
  uint8_t cmd_code;
  uint8_t pkt_len;
  uint8_t type;
} tinycmd_reset_req_type;

typedef struct
{
  uint8_t cmd_code;
  uint8_t pkt_len;
  uint8_t lock;
} tinycmd_three_lock_req_type;

// TINY_CMD_RGB_ALL_F
typedef struct
{
  uint8_t cmd_code;
  uint8_t pkt_len;
  uint8_t on; // on or off
  tinycmd_led_type led;
} tinycmd_rgb_all_req_type;

// TINY_CMD_RGB_POS_F
typedef struct
{
  uint8_t cmd_code;
  uint8_t pkt_len;
  uint8_t pos; // position
  tinycmd_led_type led;
} tinycmd_rgb_pos_req_type;

// TINY_CMD_RGB_RANGE_F
typedef struct
{
  uint8_t cmd_code;
  uint8_t pkt_len;
  uint8_t num;
  uint8_t offset;
  tinycmd_led_type led[TINYCMD_LED_MAX];
} tinycmd_rgb_range_req_type;

// TINY_CMD_RGB_SET_EFFECT_F
typedef struct
{
  uint8_t cmd_code;
  uint8_t pkt_len;
  uint8_t preset;
} tinycmd_rgb_set_effect_req_type;

// TINY_CMD_RGB_SET_PRESET_F
typedef struct
{
  uint8_t cmd_code;
  uint8_t pkt_len;
  uint8_t preset;
  uint8_t data[TINYCMD_LED_MAX*3];
} tinycmd_rgb_set_preset_req_type;

// TINY_CMD_LED_LEVEL_F
typedef struct
{
  uint8_t cmd_code;
  uint8_t pkt_len;
  uint8_t channel;
  uint8_t level;
} tinycmd_led_level_req_type;

// TINY_CMD_LED_SET_EFFECT_F
typedef struct
{
  uint8_t cmd_code;
  uint8_t pkt_len;
  uint8_t preset;
} tinycmd_led_set_effect_req_type;

// TINY_CMD_LED_SET_PRESET_F
typedef struct
{
  uint8_t cmd_code;
  uint8_t pkt_len;
  uint8_t preset;
  uint8_t block;
  uint8_t effect;
} tinycmd_led_set_preset_req_type;

// TINY_CMD_LED_CONFIG_PRESET_F
typedef struct
{
  uint8_t cmd_code;
  uint8_t pkt_len;
  uint8_t data[15];
} tinycmd_led_config_preset_req_type;

// TINY_CMD_DIRTY
typedef struct
{
  uint8_t cmd_code;
  uint8_t dirty;
} tinycmd_dirty_req_type;

typedef union
{
  uint8_t cmd_code;
  tinycmd_config_req_type              config;                   // TINY_CMD_CONFIG_F
  tinycmd_ver_req_type                 ver;                      // TINY_CMD_VER_F
  tinycmd_reset_req_type               reset;                    // TINY_CMD_RESET_F
  tinycmd_three_lock_req_type          three_lock;               // TINY_CMD_THREE_LOCK_F
  tinycmd_rgb_all_req_type             rgb_all;                  // TINY_CMD_RGB_ALL_F
  tinycmd_rgb_pos_req_type             rgb_pos;                  // TINY_CMD_RGB_POS_F
  tinycmd_rgb_range_req_type           rgb_range;                // TINY_CMD_RGB_RANGE_F
  tinycmd_rgb_set_effect_req_type      rgb_set_effect;           // TINY_CMD_RGB_SET_EFFECT_F
  tinycmd_rgb_set_preset_req_type      rgb_set_preset;           // TINY_CMD_RGB_SET_PRESET_F
  tinycmd_led_level_req_type           led_level;                // TINY_CMD_LED_LEVEL_F
  tinycmd_led_set_effect_req_type      led_set_effect;           // TINY_CMD_LED_SET_EFFECT_F
  tinycmd_led_set_preset_req_type      led_set_preset;           // TINY_CMD_LED_SET_PRESET_F
  tinycmd_led_config_preset_req_type   led_cfg_preset;           // TINY_CMD_LED_CONFIG_PRESET_F
  tinycmd_dirty_req_type               dirty;                    // TINY_CMD_DIRTY
} tinycmd_pkt_req_type;


// Response type
typedef struct
{
  uint8_t cmd_code;
  uint8_t pkt_len;
} tinycmd_rsp_type;


typedef struct
{
  uint8_t cmd_code;
  uint8_t pkt_len;
  uint8_t version;
} tinycmd_ver_rsp_type;

typedef union
{
  uint8_t cmd_code;
  tinycmd_rsp_type gen;
  tinycmd_ver_rsp_type ver;
} tinycmd_pkt_rsp_type;

#endif // TINYCMDPKT_H

