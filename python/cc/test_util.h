// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef TINK_PYTHON_CC_TEST_UTIL_H_
#define TINK_PYTHON_CC_TEST_UTIL_H_

#include "tink/python/cc/python_file_object_adapter.h"


namespace crypto {
namespace tink {
namespace test {

// PythonFileObjectAdapter for testing.
class TestPythonFileObjectAdapter : public PythonFileObjectAdapter {
 public:
  util::StatusOr<int> Write(absl::string_view data) override {
    buffer_ += std::string(data);
    return data.size();
  }

  util::Status Close() override { return util::OkStatus(); }

  std::string* GetBuffer() { return &buffer_; }

 private:
  std::string buffer_;
};

}  // namespace test
}  // namespace tink
}  // namespace crypto


#endif  // TINK_PYTHON_CC_TEST_UTIL_H_