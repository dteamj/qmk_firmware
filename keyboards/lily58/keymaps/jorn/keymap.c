#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _QWERTY_L,
  _QWERTY_R,
  _VI,
  _VI_STRONG,
  _DOWN_L,
  _DOWN_R,
  _NUM,
  _ADJUST,
};

// custom keys
enum my_keycodes {
	K_BRO = SAFE_RANGE,
	K_BRC
  };
uint8_t mod_state;


#define MO_QYL  MO(_QWERTY_L)
#define MO_QYR  MO(_QWERTY_R)
#define MO_DNL  MO(_DOWN_L)
#define MO_DNR  MO(_DOWN_R)
#define MO_NUM  MO(_NUM)
#define MO_VI   MO(_VI)
#define MO_VISG MO(_VI_STRONG)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* QWERTY
┌─────────────────────────────────────────┐                    ┌─────────────────────────────────────────┐
| ENT  | BSPC |  DEL |  SPC | SHFT | PSCN |                    |  F2  |  F3  |  F4  |  F5  |  F10 |  F11 |
|──────+──────+──────+──────+──────+──────|                    |──────+──────+──────+──────+──────+──────|
| `    |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  (   |
|──────+──────+──────+──────+──────+──────|                    |──────+──────+──────+──────+──────+──────|
| Tab  |g  A  |a  S  |s  D  |c  F  |   G  |───────┐    ┌───────|   H  |c  J  |s  K  |a  L  |g SPC | ENT  |
|──────+──────+──────+──────+──────+──────|  CTRL |    |       |──────+──────+──────+──────+──────+──────|
| ESC  |   Z  |   X  |   C  |   V  |   B  |───────|    |───────|   N  |   M  |   ─  |   =  |   '  |  )   |
└─────────────────────────────────────────/       /     \      \─────────────────────────────────────────┘
                  |  Alt |  QTY |  DWN | /   VI  /       \ SHFT \  |  DWN |  QTY |  GUI |
                  |      |      |      |/       /         \      \ |      |      |      |
                  └────────────────────────────'           '──────'┘────────────────────┘
 */

 [_QWERTY] = LAYOUT(
  KC_ENT,      KC_BSPC,   KC_DEL,     KC_SPC,     KC_LSFT,    KC_PSCR,                            KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F10,     KC_F11,
  KC_GRV,      KC_Q,      KC_W,       KC_E,       KC_R,       KC_T,                               KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       K_BRO,
  KC_TAB,      KC_A,      KC_S,       KC_D,       KC_F,       KC_G,                               KC_H,       KC_J,       KC_K,       KC_L,       KC_SPC,     KC_ENT,
  KC_ESC,      KC_Z,      KC_X,       KC_C,       KC_V,       KC_B,    KC_LCTL,      XXXXXXX,     KC_N,       KC_M,       KC_MINS,    KC_EQL,     KC_QUOT,    K_BRC,
                    		    	KC_LALT,   MO_QYR,    MO_DNR,     MO_VI,                    KC_LSFT,   MO_DNL,    MO_QYL,     KC_RGUI
),

 [_QWERTY_L] = LAYOUT(
  KC_ENT,      KC_BSPC,   KC_DEL,     KC_SPC,     KC_LSFT,    KC_PSCR,                            KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F10,     KC_F11,
  KC_GRV,      KC_Q,      KC_W,       KC_E,       KC_R,       KC_T,                               XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  KC_TAB,      KC_A,      KC_S,       KC_D,       KC_F,       KC_G,                               XXXXXXX,    KC_LCTL,    KC_LSFT,    KC_LALT,    KC_RGUI,    XXXXXXX,
  KC_ESC,      KC_Z,      KC_X,       KC_C,       KC_V,       KC_B,    _______,      _______,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
               		    	_______,   _______,    _______,     _______,                    _______,   _______,    _______,     _______
),

 [_QWERTY_R] = LAYOUT(
  KC_ENT,      KC_BSPC,   KC_DEL,     KC_SPC,     KC_LSFT,    KC_PSCR,                            KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F10,     KC_F11,
  XXXXXXX,     XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       K_BRO,
  XXXXXXX,     KC_RGUI,   KC_LALT,    KC_LSFT,    KC_LCTL,    XXXXXXX,                            KC_H,       KC_J,       KC_K,       KC_L,       KC_SPC,     KC_ENT,
  XXXXXXX,     XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,      _______,  KC_N,       KC_M,       KC_MINS,    KC_EQL,     KC_QUOT,    K_BRC,
                    		    	_______,   _______,    _______,     _______,                    _______,   _______,    _______,     _______
),

/* VI
┌─────────────────────────────────────────┐                    ┌─────────────────────────────────────────┐
|      |      |      |      |      |      |                    |      |      |      |      |      |      |
|──────+──────+──────+──────+──────+──────|                    |──────+──────+──────+──────+──────+──────|
|      |      | Left | Alt  | TAB  | NUM  |                    | BSPC | C-DOT| C-/  | DEL  | C-P  | C-SPC|
|──────+──────+──────+──────+──────+──────|                    |──────+──────+──────+──────+──────+──────|
| A─TAB|      |  ALT | SHFT | CTRL | VI++ |───────┐    ┌───────| Left | Down |  Up  | Right| SPC  | ENT  |
|──────+──────+──────+──────+──────+──────|  CTRL |    |       |──────+──────+──────+──────+──────+──────|
| C-A  |  C-Z | C-X  | C-C  | C-V  | A-V  |───────|    |───────| A-V  | C-V  | C-C  | C-X  | C-Z  | C-A  |
└─────────────────────────────────────────/       /     \      \─────────────────────────────────────────┘
                  |  Alt |  QTY |  DWN | /   VI  /       \ SHFT \  |  DWN |  QTY |  GUI |
                  |      |      |      |/       /         \      \ |      |      |      |
                  └────────────────────────────'           '──────'┘────────────────────┘
 */

[_VI] = LAYOUT(
  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                        XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,
  XXXXXXX,    XXXXXXX,    KC_LEFT,    KC_LALT,    KC_TAB,     MO_NUM,                         KC_BSPC,    C(KC_DOT),  C(KC_SLSH),  KC_DEL,     C(KC_P),    C(KC_SPC),
  A(KC_TAB),  XXXXXXX,    KC_LALT,    KC_LSFT,    KC_LCTL,    MO_VISG,                 	      KC_LEFT,    KC_DOWN,    KC_UP,       KC_RGHT,    _______,    _______,
  C(KC_A),	  C(KC_Z),    C(KC_X),    C(KC_C),    C(KC_V),    A(KC_V),   _______,    _______, A(KC_V),    C(KC_V),    C(KC_C),     C(KC_X),    C(KC_Z),    C(KC_A),
                             _______,    _______,    _______,    _______,                 _______,     _______,    _______,    _______
),

[_VI_STRONG] = LAYOUT(
  _______,    _______,    _______,    _______,    _______,    _______,                       _______,    _______,    _______,    _______,    _______,    _______,
  _______,    _______,    _______,    _______,    _______,    _______,                       _______,    _______,    _______,    _______,    _______,    _______,
  _______,    _______,    _______,    _______,    _______,    _______,                       KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     _______,    _______,
  _______,	  _______,    _______,    _______,    _______,    _______,  _______,    _______, _______,    _______,    _______,    _______,    _______,    _______,
                             _______,    _______,    _______,    _______,                 _______,     _______,    _______,    _______
),

/* DOWN
┌─────────────────────────────────────────┐                    ┌─────────────────────────────────────────┐
|  F12 |  F1  |   F2 |   F3 |   F4 |   F5 |                    |  F6  |   F7 |   F8 |   F9 |  F10 | F11  |
|──────+──────+──────+──────+──────+──────|                    |──────+──────+──────+──────+──────+──────|
|      |  1   |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  {   |
|──────+──────+──────+──────+──────+──────|                    |──────+──────+──────+──────+──────+──────|
|   |  |   /  |   .  |   ,  |   :  |   ;  |───────┐    ┌───────|   *  |   #  |   ?  |   !  |  SPC | ENT  |
|──────+──────+──────+──────+──────+──────|  CTRL |    |       |──────+──────+──────+──────+──────+──────|
|      |   \  |      |   ^  |   @  |   <  |───────|    |───────|   >  |   $  |   %  |   &  |      |   }  |
└─────────────────────────────────────────/       /     \      \─────────────────────────────────────────┘
                  |  Alt |  QTY |  DWN | /   VI  /       \ SHFT \  |  DWN |  QTY |  GUI |
                  |      |      |      |/       /         \      \ |      |      |      |
                  └────────────────────────────'           '──────'┘────────────────────┘
 */

[_DOWN_L] = LAYOUT(
  KC_F12,      KC_F1,     KC_F2,      KC_F3,	  KC_F4,      KC_F5,                             KC_F6,      KC_F7,      KC_F8,      KC_F9,    KC_F10,     KC_F11,
  XXXXXXX,     KC_1,      KC_2,		  KC_3,   	  KC_4,       KC_5,                              KC_6,     	 KC_7,       KC_8,       KC_9,     KC_0,       S(KC_LBRC),
  S(KC_BSLS),  KC_SLSH,   KC_DOT, 	  KC_COMM, 	  S(KC_SCLN), KC_SCLN,                      	 XXXXXXX,    KC_LCTL,    KC_LSFT,    KC_LALT,  KC_RGUI,    XXXXXXX,
  XXXXXXX,	   KC_BSLS,   XXXXXXX,	  S(KC_6),    S(KC_2),    S(KC_COMM), _______,  	_______, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,    S(KC_RBRC),
                             _______,    _______,    _______,    _______,                 _______,     _______,    _______,    _______
),

[_DOWN_R] = LAYOUT(
  KC_F12,      KC_F1,     KC_F2,      KC_F3,	  KC_F4,      KC_F5,                             KC_F6,      KC_F7,      KC_F8,      KC_F9,    KC_F10,     KC_F11,
  XXXXXXX,     KC_1,      KC_2,		  KC_3,   	  KC_4,       KC_5,                              KC_6,    	 KC_7,       KC_8,       KC_9,     KC_0,       S(KC_LBRC),
  XXXXXXX,     KC_RGUI,   KC_LALT,    KC_LSFT,    KC_LCTL,    XXXXXXX,                      	 S(KC_8),  	 S(KC_3),  	 S(KC_SLSH), S(KC_1),  _______,    _______,
  XXXXXXX,     XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, _______,     	_______, S(KC_DOT),  S(KC_4),  	 S(KC_5),    S(KC_7),  XXXXXXX,    S(KC_RBRC),
                             _______,    _______,    _______,    _______,                 _______,     _______,    _______,    _______
),

/* NUM
┌─────────────────────────────────────────┐                    ┌─────────────────────────────────────────┐
|      |      |      |      |      |      |                    |   <  |   >  |   $  |   %  |   &  |   ^  |
|──────+──────+──────+──────+──────+──────|                    |──────+──────+──────+──────+──────+──────|
|      |      |      |      |      |      |                    | BSPC |   7  |   8  |   9  |   *  |   /  |
|──────+──────+──────+──────+──────+──────|                    |──────+──────+──────+──────+──────+──────|
|      |      | Left | Alt  | TAB  |      |───────┐    ┌───────|   .  |   4  |   5  |   6  |   +  |   =  |
|──────+──────+──────+──────+──────+──────|  CTRL |    |       |──────+──────+──────+──────+──────+──────|
|      |      |      |      |      |      |───────|    |───────|   0  |   1  |   2  |   3  |   ─  |   ,  |
└─────────────────────────────────────────/       /     \      \─────────────────────────────────────────┘
                  |  Alt |  QTY |  DWN | /   VI  /       \ SHFT \  |  DWN |  QTY |  GUI |
                  |      |      |      |/       /         \      \ |      |      |      |
                  └────────────────────────────'           '──────'┘────────────────────┘
 */
  [_NUM] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   S(KC_COMM), S(KC_DOT),  S(KC_4),  S(KC_5), S(KC_7),   S(KC_6),
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_BSPC,    KC_7,       KC_8,     KC_9,    S(KC_8),   KC_SLSH,
  XXXXXXX, XXXXXXX, KC_LEFT, KC_LALT, KC_TAB,  XXXXXXX,                   KC_DOT,     KC_4,       KC_5,     KC_6,    S(KC_EQL), KC_EQL,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_0,       KC_1,       KC_2, 	KC_3,    KC_MINS,   KC_COMM,
                        _______, _______, _______, _______,            _______,  _______, _______, _______
  ),

/* ADJUST

 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

// layer_state_t layer_state_set_user(layer_state_t state) {
// return update_tri_layer_state(state, _VI, _DOWN, _ADJUST);
// }

// SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master())
        // return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
        return rotation; // flips the display 180 degrees if offhand
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // If you want to change the display of OLED, you need to change here
        oled_write_ln(read_layer_state(), false);
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);
        // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
        // oled_write_ln(read_host_led_state(), false);
        // oled_write_ln(read_timelog(), false);
    } else {
        oled_write_ln(read_layer_state(), false);
        // oled_write(read_logo(), false);
    }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // some oled stuff
    if (record->event.pressed) {
#ifdef OLED_ENABLE
        set_keylog(keycode, record);
#endif
        // set_timelog();
    }

    mod_state = get_mods();
    switch (keycode) {
        case K_BRO: {
            static bool     bro_registered;
            static uint16_t bro_keycode;
            if (record->event.pressed) {
                // Do something when pressed
                // without shift we sende `(`
                // with shift we send `[`
                // `{` we handle in down layer
                bro_registered = true;
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    bro_keycode = KC_LBRC;
                } else {
                    set_mods(MOD_MASK_SHIFT);
                    bro_keycode = KC_9;
                }
                register_code(bro_keycode);
                set_mods(mod_state);
            } else {
                // Do something else when release
                if (bro_registered) {
                    unregister_code(bro_keycode);
                    bro_registered = false;
                }
            }
            return false; // Skip all further processing of this key
        }
        case K_BRC: {
            static bool     brc_registered;
            static uint16_t brc_keycode;
            if (record->event.pressed) {
                // Do something when pressed
                // without shift we sende `)`
                // with shift we send `]`
                // `}` we handle in down layer
                brc_registered = true;
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    brc_keycode = KC_RBRC;
                } else {
                    set_mods(MOD_MASK_SHIFT);
                    brc_keycode = KC_0;
                }
                register_code(brc_keycode);
                set_mods(mod_state);
            } else {
                // Do something else when release
                if (brc_registered) {
                    unregister_code(brc_keycode);
                    brc_registered = false;
                }
            }
            return false; // Skip all further processing of this key
        }
        default:
            return true; // Process all other keycodes normally
    }
}
