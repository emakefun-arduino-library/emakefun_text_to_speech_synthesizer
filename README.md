# VoiceSynthesizer

`VoiceSynthesizer`用于控制语音合成模块的主类

## API使用文档

### 枚举定义

#### 文本数据编码类型

| VoiceSynthesizer::**TextEncodingType** | 值 | 描述 |
| --- | --- | --- |
| VoiceSynthesizer::TextEncodingType::**kTextEncodingTypeGb23212** | 0x00 | GB2312 |
| VoiceSynthesizer::TextEncodingType::**kTextEncodingTypeGbk** | 0x01 | GBK |
| VoiceSynthesizer::TextEncodingType::**kTextEncodingTypeBig5** | 0x02 | BIG5 |
| VoiceSynthesizer::TextEncodingType::**kTextEncodingTypeUtf16le** | 0x03 | UTF16LE |
| VoiceSynthesizer::TextEncodingType::**kTextEncodingTypeUtf8** | 0x04 | UTF8 |

#### 文本数据最大字节数

| | 值 | 描述 |
| --- | --- | --- |
| VoiceSynthesizer::**kTextSizeMax** | 50 | 文本数据最大字节数 |

#### 缓存块索引最大值

| | 值 | 描述 |
| --- | --- | --- |
| VoiceSynthesizer::**kCacheIndexMax** | 15 | 缓存块索引最大值 |

#### 缓存合成播放次数范围

| | 值 | 描述 |
| --- | --- | --- |
| VoiceSynthesizer::**kSynthesizingCountMin** | 1 | 从缓存合成播放次数的最小值 |
| VoiceSynthesizer::**kSynthesizingCountMax** | 15 | 从缓存合成播放次数的最小值 |

### 构造函数

#### `VoiceSynthesizer()`

- 描述：构造函数。
- 返回值：无。

### 启动合成并播放

#### `void StartSynthesizing(const char* text, uint8_t text_size, const TextEncodingType text_encoding_type)`

- 描述：启动合成并播放指定文本。
- 参数：
  - `text`：文本数据指针，不能为空。
  - `text_size`：文本字节大小，值范围：0 < text_size <= 50，参考[kTextSizeMax](#文本数据最大字节数)
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

#### `void PushTextToCache(const char* text, uint8_t text_size, const uint8_t cache_index)`

- 描述：将文本上传到指定缓存块中。
- 参数：
  - `text`：文本数据指针，不能为空。
  - `text_size`：文本字节大小，值范围：0 < text_size <= 50，参考[kTextSizeMax](#文本数据最大字节数)
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

### 合成播放文本

```c++
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
```

### 从缓存区域合成播放文本

```c++
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
```

### 合成播放控制

```c++
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
```
