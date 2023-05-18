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
  // 定义文本，utf-8编码格式
  String text("一二三四五");

  // 开始以utf-8编码格式合成播放文本
  voice_synthesizer.StartSynthesizing(text.c_str(), text.length(), VoiceSynthesizer::TextEncodingType::kTextEncodingTypeUtf8);

  delay(2000);
}