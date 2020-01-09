# スイッチテスター用キーマップ

## 概要

　スイッチのActuationPoint（動作点）の確認が出来る展示向けキーマップです　　

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

* 通常のキー割り当てを無くしてテスト用に特化
* OLED（オプション）でキーの動作点を確認出来る
* LED（オプション）でキー動作点を確認出来る

## LED発光オプションの設定方法

　LTADを押し続けている状態でAdjustレイヤーを操作出来ます。  
* RST: ソフトリセット
* ROFF: LEDオフ
* RGB0: LED全点灯タイプ0　色合い固定のボタン反応エフェクト
* RGB1: LED全点灯タイプ1　全LED同色点灯　時間による色合い変化エフェクト
* RGB2: LED全点灯タイプ2　全LEDレインボー点灯　時間による色合い変化エフェクト
* RGB3: LED全点灯タイプ3　スネークエフェクト
* LHUI: Hue+ 色合いを変更
* LHUD: Hue- 色合いを変更
* LSAI: Saturation+ 色の濃さを変更
* LSAD: Saturation- 色の濃さを変更
* LVAI: Value+ 明るさを変更
* LVAD: Value- 明るさを変更

```c

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
       LTAD, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX \
  //|------+------+------+------+-------------+------+------+------+------|
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
        RST, XXXXX, XXXXX, XXXXX,  RGB0, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
       ROFF,  LHUI,  LSAI,  LVAI,  RGB1, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
      XXXXX,  LHUD,  LSAD,  LVAD,  RGB2, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+-------------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX,  RGB3, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX \
  //|------+------+------+------+-------------+------+------+------+------|
  )
};

```
