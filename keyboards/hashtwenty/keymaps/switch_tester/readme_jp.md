# スイッチテスター用キーマップ

## 概要

　#ash2entyはスイッチのホットスワップに対応しているので、販売されているスイッチテスターを気軽に差し込んでActuationPoint（動作点）の確認が出来るようなキーマップを作成しました。  

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
        RST, XXXXX, XXXXX, XXXXX,  ROFF, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
      XXXXX,  LHUI,  LSAI,  LVAI,  RGB1, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
      XXXXX,  LHUD,  LSAD,  LVAD,  RGB2, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+-------------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX,  RGB3, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX \
  //|------+------+------+------+-------------+------+------+------+------|
  )
};

```