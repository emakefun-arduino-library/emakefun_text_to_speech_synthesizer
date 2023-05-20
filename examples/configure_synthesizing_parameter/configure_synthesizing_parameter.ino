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
  // 定义文本，utf-8编码格式，文本前面增加[v1]来标注音量，以音量为10进行合成播放
  // 文本标注：设置音量格式：[v*]，其中*的范围是0 ~ 10，音量值默认音量为5，10 对应到最高音量
  // 更多文本标注参数见文档
  const String text("[v1]一二三四五"); // 文本前面增加[v1]来标注音量，以音量为1进行合成播放

  // 开始以utf-8编码格式合成播放文本
  text_to_speech_synthesizer.StartSynthesizing(text, TextToSpeechSynthesizer::TextEncodingType::kTextEncodingTypeUtf8);

  delay(2000);

  // 定义文本，utf-8编码格式，文本前面增加[v10]来标注音量，以音量为10进行合成播放
  // 文本标注：设置音量格式：[v*]，其中*的范围是0 ~ 10，音量值默认音量为5，10 对应到最高音量
  // 更多文本标注参数见文档
  const String text("[v10]一二三四五"); // 文本前面增加[v10]来标注音量，以音量为10进行合成播放

  // 开始以utf-8编码格式合成播放文本
  text_to_speech_synthesizer.StartSynthesizing(text, TextToSpeechSynthesizer::TextEncodingType::kTextEncodingTypeUtf8);

  delay(2000);
}