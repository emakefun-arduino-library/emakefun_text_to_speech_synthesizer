#pragma once

#include <WString.h>
#include <stdint.h>

/**
 * @class TextToSpeechSynthesizer
 * @brief 语音合成主类
 */
class TextToSpeechSynthesizer {
 public:
  /**
   * @enum TextEncodingType
   * @brief 文本编码类型
   */
  enum TextEncodingType : uint8_t {
    kTextEncodingTypeGb23212 = 0x00, /**< GB2312 */
    kTextEncodingTypeGbk = 0x01,     /**< GBK */
    kTextEncodingTypeBig5 = 0x02,    /**< BIG5 */
    kTextEncodingTypeUtf16le = 0x03, /**< UTF16LE */
    kTextEncodingTypeUtf8 = 0x04,    /**< UTF8 */
  };

  enum : uint8_t {
    kCacheIndexMax = 15, /**< 缓存块索引最大值 */
  };

  enum : uint8_t {
    kTextSizeMax = 250, /**< 文本数据最大字节数 */
  };

  enum : uint8_t {
    kSynthesizingCountMin = 1,  /**< 从缓存合成播放次数的最小值 */
    kSynthesizingCountMax = 15, /**< 从缓存合成播放次数的最大值 */
  };

  /**
   * @brief 构造函数
   */
  TextToSpeechSynthesizer();

  /**
   * @brief 启动合成文本并播放
   * @param[in] text 类型：String，文本数据地址，数据长度不大于250个字节
   * @param[in] text_encoding_type 文本编码类型，参考 @ref TextEncodingType
   */
  void StartSynthesizing(const String& text, const TextEncodingType text_encoding_type);

  /**
   * @brief 停止合成播放
   */
  void StopSynthesizing();

  /**
   * @brief 暂停合成播放
   */
  void PauseSynthesizing();

  /**
   * @brief 恢复合成播放
   */
  void ResumeSynthesizing();

  /**
   * @brief 将文本内容上传到指定缓存块
   * @param[in] text 类型：String，文本数据地址，数据长度不大于250个字节
   * @param[in] cache_index 缓存块索引，范围参考 0 ~ @ref kCacheIndexMax
   */
  void PushTextToCache(const String& text, const uint8_t cache_index);

  /**
   * @brief 从缓存块0开始合成文本并播放
   * @param[in] text_encoding_type 文本编码类型，参考 @ref TextEncodingType
   * @param[in] synthesizing_count 合成播放次数，范围1 ~ 15，参考 @ref kSynthesizingCountMin ~ @ref kSynthesizingCountMax
   */
  void StartSynthesizingFromCache(const TextEncodingType text_encoding_type, uint8_t synthesizing_count = 1);

 private:
  TextToSpeechSynthesizer(const TextToSpeechSynthesizer&) = delete;
  TextToSpeechSynthesizer& operator=(const TextToSpeechSynthesizer&) = delete;
};

/**
 * @example synthesize_text.ino
 * 合成文本并播放
 */

/**
 * @example synthesize_from_cache.ino
 * 将文本上传到缓存并合成播放
 */

/**
 * @example synthesizing_control.ino
 * 合成文本播放流程控制
 */

/**
 * @example configure_synthesizing_parameter.ino
 * 合成文本播放的详细参数设置
 */