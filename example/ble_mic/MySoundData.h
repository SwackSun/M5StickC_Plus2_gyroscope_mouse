#pragma once
#include <BluetoothA2DPSource.h>

class MySoundData : public SoundData {
public:
    MySoundData() : current_pos(0), loop(false) {}

    void setDataRaw(uint8_t* data, int32_t len) override {
        // Store the raw data if necessary
        // For this example, we won't use this function
    }

    int32_t get2ChannelData(int32_t pos, int32_t len, uint8_t *data) override {
        // Copy audio data to the provided buffer
        int32_t bytes_to_copy = len < (buffer_size - pos) ? len : (buffer_size - pos);
        memcpy(data, audio_buffer + pos, bytes_to_copy);
        current_pos = pos + bytes_to_copy;
        return bytes_to_copy;
    }

    int32_t getData(int32_t pos, Frame &channels) override {
        // Implement this if needed, depending on your audio requirements
        return 0; // Placeholder
    }

    void setLoop(bool loop) {
        this->loop = loop;
    }

    bool doLoop() {
        return loop;
    }

    void setAudioBuffer(uint8_t* buffer, size_t size) {
        audio_buffer = buffer;
        buffer_size = size;
        current_pos = 0; // Reset position
    }

private:
    uint8_t* audio_buffer;
    size_t buffer_size;
    int32_t current_pos;
    bool loop;
};