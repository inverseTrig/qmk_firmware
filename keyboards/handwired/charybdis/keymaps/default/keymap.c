#include QMK_KEYBOARD_H

// Layers
enum layers {
    _DEFAULT = 0,
    _BUTTON,
    _MEDIA,
    _NAV,
    _NUM,
    _SYM,
    _FUN,
    _BOOT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ' │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   
      *           │ESC├───┐           ┌───┐
      *           └───┤SPC├───┐   ┌───┤BSP│
      *               └───┤TAB│   │ENT├───┘
      *                   └───┘   └───┘
      */
    [_DEFAULT] = LAYOUT_split(
        KC_Q,               KC_W,          KC_E,                KC_R,              KC_T,                  KC_Y,              KC_U,          KC_I,             KC_O,          KC_P,
        LGUI_T(KC_A),       LALT_T(KC_S),  LCTL_T(KC_D),        LSFT_T(KC_F),      KC_G,                  KC_H,              LSFT_T(KC_J),  LCTL_T(KC_K),     LALT_T(KC_L),  LGUI_T(KC_QUOTE),
        LT(_BUTTON, KC_Z),  KC_X,          KC_C,                KC_V,              KC_B,                  KC_N,              KC_M,          KC_COMM,          KC_DOT,        LT(_BUTTON, KC_SLSH),
                                           LT(_MEDIA, KC_ESC),  LT(_NAV, KC_SPC),  LT(_FUN, KC_TAB),      LT(_SYM, KC_ENT),  LT(_NUM, KC_BSPC)
    ),
    [_BUTTON] = LAYOUT_split(
        KC_TRNS,  KC_TRNS,  C(KC_C),  G(KC_Z),  G(S(KC_Z)),      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        G(KC_A),  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  G(KC_X),  G(KC_C),  G(KC_V),  G(S(KC_V)),      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                            KC_TRNS,  KC_TRNS,  KC_TRNS,         KC_TRNS,  KC_TRNS
    ),
    [_MEDIA] = LAYOUT_split(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_BRID,  KC_BRIU,  KC_MPRV,  KC_MNXT,
        KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_TRNS,      KC_TRNS,  KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_MPLY,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                            KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS
    ),
    [_NAV] = LAYOUT_split(
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_TRNS,      KC_TRNS,  KC_HOME,  KC_UP,    KC_END,   KC_TRNS,
        KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_TRNS,      KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                            KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS
    ),
    [_NUM] = LAYOUT_split(
        KC_LBRC,  KC_7,  KC_8,    KC_9,  KC_RBRC,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_SCLN,  KC_4,  KC_5,    KC_6,  KC_EQL,       KC_TRNS,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,
        KC_GRV,   KC_1,  KC_2,    KC_3,  KC_BSLS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                         KC_DOT,  KC_0,  KC_MINS,      KC_TRNS,  KC_TRNS
    ),
    [_SYM] = LAYOUT_split(
        KC_LCBR,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RCBR,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_COLN,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_PLUS,      KC_TRNS,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,
        KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_PIPE,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                            KC_LPRN,  KC_RPRN,  KC_UNDS,      KC_TRNS,  KC_TRNS
    ),
    [_FUN] = LAYOUT_split(
        KC_F12,  KC_F7,  KC_F8,      KC_F9,    KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_F11,  KC_F4,  KC_F5,      KC_F6,    KC_TRNS,      KC_TRNS,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,
        KC_F10,  KC_F1,  KC_F2,      KC_F3,    KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                         MO(_BOOT),  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS
    ),
    [_BOOT] = LAYOUT_split(
        QK_RBT,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  QK_BOOT,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                            KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS
    ),
};
