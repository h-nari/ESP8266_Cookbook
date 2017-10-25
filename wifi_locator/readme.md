# wifi_locator

wifiで受信したSSIDの情報から現在位置を調べる。

<a href="https://blog.squix.org/2017/01/esp8266-planespotter-color.html">squix78氏のESP8266 PlaneSpotterColor</a>で使われている方法。

plane_spotterのプログラムからWifiLocatorクラスを切り出した。

## 原理

* wifiの情報(アクセスポイントのSSID, MACアドレス、信号強度)から位置情報を提供するサイトが複数存在する。
* このプログラムでは mylnikov.orgから位置情報を取得する。
* WiFiScanクラスでアクセスポイントの情報を取得
* 情報を文字列として結合し、base64エンコードしてapi.mylnikov.orgに送信
* 帰ってきたjson形式の文字列をJsonStreamingParserで解釈し、位置情報（緯度、経度）を取得

<center>
<img  src="https://github.com/h-nari/ESP8266_Cookbook/blob/master/img/fig171024a1.png?raw=true"/></center>

## 必要なライブラリ

* [squix78/json-streaming-parser: Arduino library for parsing potentially huge json streams on devices with scarce memory](https://github.com/squix78/json-streaming-parser "squix78/json-streaming-parser: Arduino library for parsing potentially huge json streams on devices with scarce memory")

## 改造箇所

* 位置情報の取得に失敗することがあるので、updateLocation()メソッドが成功したかどうかをbooleanで返すように変更した。成功したら true, 失敗したら falseを返す。


## 実行結果

* プログラムを走らせると、シリアルモニタに推定現在位置( 緯度、経度)が表示される。
* 緯度、経度部分をコピーし、Google Mapで検索すると位置を確認できる。（適当に離れている）

<center>
<img width="400" src="https://github.com/h-nari/ESP8266_Cookbook/blob/master/img/sc171024a1.png?raw=true"/></center>
