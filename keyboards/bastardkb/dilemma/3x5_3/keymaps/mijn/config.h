#define NO_AUTO_SHIFT_ALPHA 1

#undef TAPPING_TERM
#define TAPPING_TERM 200
#define LONG_TAPPING_TERM 490
#define TAPPING_TERM_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD

#define COMBO_COUNT 1

/** Dilemma-specific features. */

#ifdef POINTING_DEVICE_ENABLE
// Flip horizontal direction for drag-scroll.
#    define DILEMMA_DRAGSCROLL_REVERSE_X
// #define DILEMMA_DRAGSCROLL_REVERSE_Y
#endif // POINTING_DEVICE_ENABLE
