#include <Arduino.h>

// 包含头文件 text_to_speech_synthesizer.h
#include "text_to_speech_synthesizer.h"

// 定义text_to_speech_synthesizer
TextToSpeechSynthesizer text_to_speech_synthesizer;

void setup() {
  Serial.begin(115200);
  Serial.println("setup");
}

void loop() {
  // 定义文本，utf-8编码格式
  String text("一二三四五");

  // 开始以utf-8编码格式合成播放文本
  text_to_speech_synthesizer.StartSynthesizing(text.c_str(), text.length(), TextToSpeechSynthesizer::TextEncodingType::kTextEncodingTypeUtf8);

  delay(2000);
}