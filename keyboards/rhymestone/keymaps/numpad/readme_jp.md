# テンキー用キーマップ

## 概要

　左手仕様で組んだ片方のRhymestoneだけで動作するテンキー用キーマップです  

## rules.mkの設定項目

rules.mkにはコンパイル時に機能を取捨選択する設定項目があります。yesにするとほとんどはバイナリサイズが増えますので、適宜設定してください。  

### MOUSEKEY_ENABLE

マウスカーソルをキーボードから操作出来るマウスキーを使う場合はyes。  
いくつかのキーマップにはAdjustレイヤーにマウスカーソルを操作するキーが割り当てられています。  

MOUSEKEY_ENABLE = no | yes

### TAP_DANCE_ENABLE

タップダンス機能を使用する場合はyes。  

TAP_DANCE_ENABLE = no | yes

### RGBLIGHT_ENABLE

バックライト、アンダーグロー用としてはんだ付けしたRGBのLEDがあるならならyes。  
Adjustレイヤーでパラメータを制御出来るようになっています。  
RGBLIGHT_ENABLE = no | yes

### OLED_DRIVER_ENABLE

OLEDモジュールを取り付けているならyes。  
OLEDモジュールを取り付けずにこの項目をyesにしている場合、キー検出のパフォーマンスが落ちて正しくキーを拾えないことがあるので注意してください。  

OLED_DRIVER_ENABLE = no | yes

### LTO_ENABLE

古い互換機能を削除したりなどのビルドオプションを改善します。バイナリサイズが大きくなってビルドでエラーが出た場合にyesとするとファイルサイズが小さくなりエラーがでなくなることがあります。  

LTO_ENABLE = no | yes

## config.h

### USE_HASHTWENTY

Rhymestoneのα板のファームを作成する場合は定義してください。  
#define USE_HASHTWENTY  

### MASTER_RIGHT

USBを右側に着けたい場合は定義してください。  
#define MASTER_RIGHT

## 機能

* BASEレイヤーに基本的なテンキーのボタンと追加の算術演算子を割り当てています
* LOWERレイヤー(MLLOキーを押しながら操作)に16進数用のA-Fとカッコや#等の記号を割り当てています
* ADJUSTレイヤー(MLLOキーを押しながらDLADJキーを押下すると固定される。DLBASキーでBASEレイヤーに戻ります)にNumlockキーや設定キーを割り当ててます

```c

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
         P7,    P8,    P9,  QUOT,  BSPC, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
         P4,    P5,    P6,  PMNS,  PSLS, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
         P1,    P2,    P3,  PPLS,  PAST, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
       MLLO,    P0,  PDOT,   SPC,  PENT, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX \
  //|------+------+------+------+-------------+------+------+------+------|
  ),

  [_LOWER] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
          A,     B,     C,  HASH,   DEL, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
          D,     E,     F,  PEQL,  PERC, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
       RSBR,  REBR,  RBRC,  BSLS,  UNDS, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+-------------+------+------+------+------|
      _____,  KP00,  PCMM,   TAB, DLADJ, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX \
  //|------+------+------+------+-------------+------+------+------+------|
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
        RST,  LRST,  KNRM,  KSWP, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
       LTOG,  LHUI,  LSAI,  LVAI, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
       LMOD,  LHUD,  LSAD,  LVAD,  NLCK, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+-------------+------+------+------+------|
      _____, _____, _____, DLBAS, _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX \
  //|------+------+------+------+-------------+------+------+------+------|
  )
};

```
