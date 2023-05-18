#include <Arduino.h>

// 包含头文件 voice_synthesizer.h
#include "voice_synthesizer.h"

// 定义voice_synthesizer
VoiceSynthesizer voice_synthesizer;

void setup() {
  Serial.begin(115200);
  Serial.println("setup");
}

void loop() {
  // 定义文本1，utf-8编码格式
  String text_1("一二三四五");

  // 将文本1内容上传到缓存块0
  voice_synthesizer.PushTextToCache(text_1.c_str(), text_1.length(), 0);

  // 定义文本2，utf-8编码格式
  String text_2("六七八九十");

  // 将文本2内容上传到缓存块1
  voice_synthesizer.PushTextToCache(text_2.c_str(), text_2.length(), 1);

  // 开始从缓存区域合成播放文本，合成播放1次
  voice_synthesizer.StartSynthesizingFromCache(VoiceSynthesizer::TextEncodingType::kTextEncodingTypeUtf8, 1);

  delay(3000);
}