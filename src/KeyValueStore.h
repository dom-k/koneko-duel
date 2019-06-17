#ifndef KONEKO_DUEL_KEYVALUESTORE_H
#define KONEKO_DUEL_KEYVALUESTORE_H

#include <string>

class KeyValueStore {
 private:
  std::string key;
  std::string value;

 public:
  KeyValueStore(std::string, std::string);
  std::string GetKey();
  void SetKey(std::string);
  std::string GetValue();
  void SetValue(std::string);
};

#endif  // KONEKO_DUEL_KEYVALUESTORE_H