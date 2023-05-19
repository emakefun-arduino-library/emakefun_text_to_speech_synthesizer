# TextToSpeechSynthesizer

`TextToSpeechSynthesizer`用于控制文本到语音合成模块的主类

## API使用文档

### 枚举定义

#### 文本数据编码类型

| TextToSpeechSynthesizer::**TextEncodingType** | 值 | 描述 |
| --- | --- | --- |
| TextToSpeechSynthesizer::TextEncodingType::**kTextEncodingTypeGb23212** | 0x00 | GB2312 |
| TextToSpeechSynthesizer::TextEncodingType::**kTextEncodingTypeGbk** | 0x01 | GBK |
| TextToSpeechSynthesizer::TextEncodingType::**kTextEncodingTypeBig5** | 0x02 | BIG5 |
| TextToSpeechSynthesizer::TextEncodingType::**kTextEncodingTypeUtf16le** | 0x03 | UTF16LE |
| TextToSpeechSynthesizer::TextEncodingType::**kTextEncodingTypeUtf8** | 0x04 | UTF8 |

#### 文本数据最大字节数

| | 值 | 描述 |
| --- | --- | --- |
| TextToSpeechSynthesizer::**kTextSizeMax** | 50 | 文本数据最大字节数 |

#### 缓存块索引最大值

| | 值 | 描述 |
| --- | --- | --- |
| TextToSpeechSynthesizer::**kCacheIndexMax** | 15 | 缓存块索引最大值 |

#### 缓存合成播放次数范围

| | 值 | 描述 |
| --- | --- | --- |
| TextToSpeechSynthesizer::**kSynthesizingCountMin** | 1 | 从缓存合成播放次数的最小值 |
| TextToSpeechSynthesizer::**kSynthesizingCountMax** | 15 | 从缓存合成播放次数的最小值 |

### 构造函数

#### `TextToSpeechSynthesizer()`

- 描述：构造函数。
- 返回值：无。

### 启动合成并播放

#### `void StartSynthesizing(const String& text, const TextEncodingType text_encoding_type)`

- 描述：启动合成并播放指定文本。
- 参数：
  - `text`：类型：`String`，文本数据地址，数据长度不大于50个字节，参考[kTextSizeMax](#文本数据最大字节数)。如果文本超过50个字节，超过部分将被截断
  - `text_encoding_type`：文本编码类型，参考[TextEncodingType](#文本数据编码类型)
- 返回值：无。

### 停止合成播放

#### `void StopSynthesizing()`

- 描述：停止当前正在合成并播放的语音。
- 返回值：无。

### 暂停合成播放

#### `void PauseSynthesizing()`

- 描述：暂停当前正在合成并播放的语音。
- 返回值：无。

### 恢复合成播放

#### `void ResumeSynthesizing()`

- 描述：恢复当前正在合成并播放的语音。
- 返回值：无。

### 上传文本到缓存块

#### `void PushTextToCache(const String& text, const uint8_t cache_index)`

- 描述：将文本上传到指定缓存块中。
- 参数：
  - `text`：类型：`String`，文本数据地址，数据长度不大于50个字节，参考[kTextSizeMax](#文本数据最大字节数)。如果文本超过50个字节，超过部分将被截断
  - `cache_index`：缓存块索引，值范围：0 <= cache_index <= 15，参考[kCacheIndexMax](#缓存块索引最大值)
- 返回值：无。

### 从缓存块合成并播放

#### `void StartSynthesizingFromCache(const TextEncodingType text_encoding_type, uint8_t synthesizing_count = 1)`

- 描述：从缓存块中合成并播放语音。
- 参数：
  - `text_encoding_type`：文本编码类型，参考[TextEncodingType](#文本数据编码类型)枚举
  - `synthesizing_count`：合成播放次数，值范围：0 <= synthesizing_count <= 15，参考[缓存合成播放次数范围](#缓存合成播放次数范围)
- 返回值：无。

## 示例程序

[合成播放文本](examples/synthesize_text/synthesize_text.ino)

[从缓存区域合成播放文本](examples/synthesize_from_cache/synthesize_from_cache.ino)

[合成播放控制](examples/synthesizing_control/synthesizing_control.ino)
