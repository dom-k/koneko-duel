#include "KeyValueStore.h"

KeyValueStore::KeyValueStore(std::string key, std::string value) {
    this->key = key;
    this->value = value;
}

std::string KeyValueStore::GetKey() { return this->key; }

void KeyValueStore::SetKey(std::string key) { this->key = key; }

std::string KeyValueStore::GetValue() { return this->value; }

void KeyValueStore::SetValue(std::string value) { this->value = value; }