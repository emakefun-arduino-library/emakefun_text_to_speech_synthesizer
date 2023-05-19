#include "text_to_speech_synthesizer.h"

#include "utility/TinyI2CMaster.h"

namespace {
constexpr uint8_t kI2cAddress = 0x40;
}

TextToSpeechSynthesizer::TextToSpeechSynthesizer() {
  TinyI2C.init();
}

void TextToSpeechSynthesizer::StartSynthesizing(const String& text, const TextEncodingType text_encoding_type) {
  auto text_size = min(text.length(), kTextSizeMax);
  TinyI2C.start(kI2cAddress, 0);
  TinyI2C.write(0xFD);
  TinyI2C.write(0x00);
  TinyI2C.write(text_size + 2);  // data size
  TinyI2C.write(0x01);
  TinyI2C.write(text_encoding_type);
  for (uint8_t i = 0; i < text_size; i++) {
    TinyI2C.write(text[i]);
  }
  TinyI2C.stop();
}

void TextToSpeechSynthesizer::StopSynthesizing() {
  TinyI2C.start(kI2cAddress, 0);
  TinyI2C.write(0xFD);
  TinyI2C.write(0x00);
  TinyI2C.write(0x01);
  TinyI2C.write(0x02);
  TinyI2C.stop();
}

void TextToSpeechSynthesizer::PauseSynthesizing() {
  TinyI2C.start(kI2cAddress, 0);
  TinyI2C.write(0xFD);
  TinyI2C.write(0x00);
  TinyI2C.write(0x01);
  TinyI2C.write(0x03);
  TinyI2C.stop();
}

void TextToSpeechSynthesizer::ResumeSynthesizing() {
  TinyI2C.start(kI2cAddress, 0);
  TinyI2C.write(0xFD);
  TinyI2C.write(0x00);
  TinyI2C.write(0x01);
  TinyI2C.write(0x04);
  TinyI2C.stop();
}

void TextToSpeechSynthesizer::PushTextToCache(const String& text, const uint8_t cache_index) {
  if (cache_index > kCacheIndexMax) {
    return;
  }

  auto text_size = min(text.length(), kTextSizeMax);
  // Serial.print("PushTextToCache, text_size:");
  // Serial.println(text_size);
  TinyI2C.start(kI2cAddress, 0);
  TinyI2C.write(0xFD);
  TinyI2C.write(0x00);
  TinyI2C.write(text_size + 2);  // data size
  TinyI2C.write(0x31);           // command
  TinyI2C.write(cache_index);
  for (uint8_t i = 0; i < text_size; i++) {
    TinyI2C.write(text[i]);
  }
  TinyI2C.stop();
}

void TextToSpeechSynthesizer::StartSynthesizingFromCache(const TextEncodingType text_encoding_type,
                                                         uint8_t synthesizing_count) {
  synthesizing_count = max(min(synthesizing_count, kSynthesizingCountMax), kSynthesizingCountMin);
  TinyI2C.start(kI2cAddress, 0);
  TinyI2C.write(0xFD);
  TinyI2C.write(0x00);
  TinyI2C.write(0x02);  // data size
  TinyI2C.write(0x32);  // command
  TinyI2C.write((synthesizing_count << 4) | text_encoding_type);
  TinyI2C.stop();
}