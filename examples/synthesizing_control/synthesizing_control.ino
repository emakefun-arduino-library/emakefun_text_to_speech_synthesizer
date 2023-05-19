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
  const String text("一二三四五六七八九十");

  // 开始以utf-8编码格式合成播放文本
  text_to_speech_synthesizer.StartSynthesizing(text, TextToSpeechSynthesizer::TextEncodingType::kTextEncodingTypeUtf8);

  // 延时1s
  delay(1000);

  // 暂停合成播放
  text_to_speech_synthesizer.PauseSynthesizing();

  // 延时1s
  delay(1000);

  // 恢复合成播放
  text_to_speech_synthesizer.ResumeSynthesizing();

  // 延时2s
  delay(1000);

  // 停止合成播放
  text_to_speech_synthesizer.StopSynthesizing();
}