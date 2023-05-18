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
  String text("一二三四五六七八九十");

  // 开始以utf-8编码格式合成播放文本
  voice_synthesizer.StartSynthesizing(text.c_str(), text.length(), VoiceSynthesizer::TextEncodingType::kTextEncodingTypeUtf8);

  // 延时1s
  delay(1000);

  // 暂停合成播放
  voice_synthesizer.PauseSynthesizing();

  // 延时1s
  delay(1000);

  // 恢复合成播放
  voice_synthesizer.ResumeSynthesizing();

  // 延时2s
  delay(1000);

  // 停止合成播放
  voice_synthesizer.StopSynthesizing();
}