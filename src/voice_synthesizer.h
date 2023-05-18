#pragma once

#include <stdint.h>

/**
 * @class VoiceSynthesizer
 * @brief 语音合成主类
 */
class VoiceSynthesizer {
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
    kTextSizeMax = 50, /**< 文本数据最大字节数 */
  };

  enum : uint8_t {
    kSynthesizingCountMin = 1,  /**< 从缓存合成播放次数的最小值 */
    kSynthesizingCountMax = 15, /**< 从缓存合成播放次数的最大值 */
  };

  /**
   * @brief 构造函数
   */
  VoiceSynthesizer();

  /**
   * @brief 启动合成文本并播放
   * @param[in] text 文本数据地址，值不为null
   * @param[in] text_size 文本字节大小，值必须大于0，最大值参考 @ref kTextSizeMax，超过的字符将被截断
   * @param[in] text_encoding_type 文本编码类型，参考 @ref TextEncodingType
   */
  void StartSynthesizing(const char* text, uint8_t text_size, const TextEncodingType text_encoding_type);

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
   * @param[in] text 文本数据地址，值不为null
   * @param[in] text_size 文本字节大小，值必须大于0，最大值参考 @ref kTextSizeMax，超过的字符将被截断
   * @param[in] cache_index 缓存块索引，范围参考 0 ~ @ref kCacheIndexMax
   */
  void PushTextToCache(const char* text, uint8_t text_size, const uint8_t cache_index);

  /**
   * @brief 从缓存块0开始合成文本并播放
   * @param[in] text_encoding_type 文本编码类型，参考 @ref TextEncodingType
   * @param[in] synthesizing_count 合成播放次数，范围参考 @ref kSynthesizingCountMin ~ kSynthesizingCountMax
   */
  void StartSynthesizingFromCache(const TextEncodingType text_encoding_type, uint8_t synthesizing_count = 1);

 private:
  VoiceSynthesizer(const VoiceSynthesizer&) = delete;
  VoiceSynthesizer& operator=(const VoiceSynthesizer&) = delete;
};