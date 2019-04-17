# US配列ライクデフォルトキーマップ

## 概要

　US配列ライクなデフォルトキーマップです。  
　win機はLowerとRaiseを押しながらAdjustキーマップに移動してKSWPキーを押してください。AltとGuiが入れ替わります。  

## キーマップの見かた

qmk_firmware\tmk_core\common\keycode.h  
に基本的なキーコードがあります。また、Keymap.cの上部にカスタムしたKC_で始まるものを登録しています。  
キーマップに書くときは「KC_」を省略して書いています。
例：KC_A → A  

Leyer Tap、Mod Tap、Tap DanceというQMKの機能を使っています。  

Layer Tapはタップで指定したキー、長押しで指定したレイヤーに移動します。  
例：LT(RAISE, KC_V) → タップでV、長押しでRAISEレイヤー移動

Mod Tapはタップで視程したキー、長押しで視程したレイヤーに移動します。  
例：LSFT_T(KC_Z) → タップでZ、長押しで左シフト

Tap Danceは指定した二つのキーをシングルタップ、ダブルタップで切り替えられます。  
例：[TD_CODO] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_DOT) → シングルタップでCOMM、ダブルタップでDOT

もう少し詳しい内容についてはQMK Documentをお読みいただくかネットを検索すれば情報が載っていますので別途検索してみてください。  

## キーマップの説明

　ベースに文字キーと最低限の記号とモデファイアキーがあります。  
　モデファイアキーと一部の記号キー、文字キーには単押し、長押しでキーの役割が変わります。

![img](https://github.com/marksard/Keyboards/raw/master/rhymestone/documents/_image/rhymestone.png)  

キーマップにある以下のキーが二つの役割をもつキーです。TabとEsc、Backspace(Bspc)、-(minus)の位置がずいぶん変わっていますが、ちょっと小指付近を多用することにはなりますが、レイヤーを移動しなくても打てるので慣れてくると操作感はレイヤー移動するよりは良くなります。

- ZSFT: 単押し＝Z　長押し＝Shift
- ESCT: 単押し＝Esc　長押し＝Ctrl
- TBAL: 単押し＝Tab　長押し＝Gui
- LGUI: 単押し＝Alt　長押し＝Alt
- MNSF: 単押し＝-　長押し＝Shift
- CODO: シングルタップ＝,　ダブルタップ＝.

　LowerとRaiseを同時押しでAdjustレイヤーを使うことが出来ます。  
　Lower+DLNPキーでNUMPADレイヤーに切り替わります。元のBaseレイヤーに戻るにはDLBSキーを押して戻します。  
　マウスキーの割り当てがありますので、もし使用したい場合はrules.mkでMOUSEKEY_ENABLE = yesにしてmakeすると使用することができます。  

## OS切り替え方法

　Adjustレイヤーにあります。LowerとRaiseを同時押しでAdjustレイヤーを使うことが出来ます。  

- KNRM: QMKのノーマル状態です。macだと正常に使える（はず）です
- KSWP: ノーマル状態のままWindowsで使用するとALTキーとGUI（win）キーが逆ですので、それを入れ換えます。Windowsユーザーはこちらのモードにしてください

## NUMPADモードについて

　Lower + DLNPキーを一度押下するとNumpadモードになります。通常モードに戻す場合はDLBSキーを押下してください。  

## IME切り替え方法

　Winの場合、LowerレイヤーにKANJIキー（半角/全角　漢字）がありますので、Lower+KANJIで切り替えてください。  

## ソフトウェアリセットについて

　キーボードにはハードウェアのリセットボタンが付いていますが、ソフトウェアリセットをかけられます。  
　LowerとRaiseを同時押しでAdjustレイヤーを使うことが出来、AdjustレイヤーのRSTを押下するとリセットがかかります。  

## LEDの点灯切り替え方法

　Adjustレイヤーにあります。LowerとRaiseを同時押しでAdjustレイヤーを使うことが出来ます。  

- LRST: LEDのリセット
- LTOG: LEDのON/OFF切り替え
- LMOD: LEDの光り方の変更
- LHUI: Hue+ 色合いを変更
- LHUD: Hue- 色合いを変更
- LSAI: Saturation+ 色の濃さを変更
- LSAD: Saturation- 色の濃さを変更
- LVAI: Value+ 明るさを変更
- LVAD: Value- 明るさを変更

```c

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
          Q,     W,     E,     R,     T,     Y,     U,     I,     O,     P,\
  //|------+------+------+------+------|------+------+------+------+------|
          A,     S,     D,     F,     G,     H,     J,     K,     L,   ENT,\
  //|------+------+------+------+------|------+------+------+------+------|
       ZSFT,     X,     C,     V,     B,     N,     M,  CODO,    UP,  MNSF,\
  //|------+------+------+------+------|------+------+------+------+------|
       ESCT,  TBAL,  LGUI, LOWER,  BSPC,   SPC, RAISE,  LEFT,  DOWN,  RGHT \
  //|------+------+------+------+-------------+------+------+------+------|
  ),

  [_NUMPAD] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
         P7,    P8,    P9,  PAST,  NLCK,    P7,    P8,    P9,  PAST,  NLCK,\
  //|------+------+------+------+------|------+------+------+------+------|
         P4,    P5,    P6,  PMNS,  PSLS,    P4,    P5,    P6,  PMNS,  PSLS,\
  //|------+------+------+------+------|------+------+------+------+------|
         P1,    P2,    P3,  PPLS,  QUOT,    P1,    P2,    P3,  PPLS,  QUOT,\
  //|------+------+------+------+------|------+------+------+------+------|
       DLBS,    P0,  PDOT,  SFEQ,  BSPC,  DLBS,    P0,  PDOT,  SFEQ,  BSPC \
  //|------+------+------+------+-------------+------+------+------+------|
  ),

  [_LOWER] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
         F1,    F2,    F3,    F4,    F5,  MINS,   EQL,  LBRC,  RBRC,  BSLS,\
  //|------+------+------+------+------|------+------+------+------+------|
         F6,    F7,    F8,    F9,   F10, XXXXX, XXXXX, XXXXX,  SCLN,  QUOT,\
  //|------+------+------+------+------|------+------+------+------+------|
       11SF,   F12,  DLNP, KANJI,   ENT, XXXXX, XXXXX,  COMM,   DOT,   GRV,\
  //|------+------+------+------+-------------+------+------+------+------|
      _____, _____, _____, _____,   DEL, _____, _____, _____, _____, _____ \
  //|------+------+------+------+-------------+------+------+------+------|
  ),

  [_RAISE] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
          1,     2,     3,     4,     5,     6,     7,     8,     9,     0,\
  //|------+------+------+------+------|------+------+------+------+------|
       EXLM,    AT,  HASH,   DLR,  PERC,  CIRC, AMPR,   ASTR,  LPRN,  RPRN,\
  //|------+------+------+------+------|------+------+------+------+------|
       LSFT, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,  PGUP, XXXXX,\
  //|------+------+------+------+-------------+------+------+------+------|
      _____, _____, _____, _____,  BSPC,  WLCK, _____,  HOME,  PGDN,   END \
  //|------+------+------+------+-------------+------+------+------+------|
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
        RST,  LRST,  KNRM,  KSWP,  CAPS, XXXXX,  WH_L,  WH_U,  HOME,  PGUP,\
  //|------+------+------+------+------|------+------+------+------+------|
       LTOG,  LHUI,  LSAI,  LVAI,  SLCK, XXXXX,  WH_R,  WH_D,   END,  PGDN,\
  //|------+------+------+------+------|------+------+------+------+------|
       LMOD,  LHUD,  LSAD,  LVAD,  NLCK, XXXXX,  BTN1,  BTN2,  MS_U, XXXXX,\
  //|------+------+------+------+-------------+------+------+------+------|
       LSFT, _____, _____, _____, XXXXX, XXXXX, _____,  MS_L,  MS_D,  MS_R \
  //|------+------+------+------+-------------+------+------+------+------|
  )
};

```