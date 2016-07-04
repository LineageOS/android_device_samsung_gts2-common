#include <utils/threads.h>
#include <utils/RefBase.h>
#include <binder/MemoryBase.h>
#include <binder/MemoryHeapBase.h>
#include <hardware/camera.h>
#include <hardware/gralloc.h>
#include <camera/Camera.h>
#include <camera/CameraParameters.h>

#include "ExynosCamera.h"


namespace android {

ExynosCamera::ExynosCamera(int cameraId, camera_device_t *dev) {
    // Empty
}

ExynosCamera::~ExynosCamera() {
    // Empty
}

status_t ExynosCamera::setPreviewWindow(preview_stream_ops *w) {
    return 0;
}

void ExynosCamera::setCallbacks(camera_notify_callback notify_cb,
        camera_data_callback data_cb,
        camera_data_timestamp_callback data_cb_timestamp,
        camera_request_memory get_memory,
        void *user) {
    // Empty
}

void ExynosCamera::enableMsgType(int32_t msgType) {
    // Empty
}

void ExynosCamera::disableMsgType(int32_t msgType) {
    // Empty
}

bool ExynosCamera::msgTypeEnabled(int32_t msgType) {
    return 0;
}

void ExynosCamera::startPreview() {
    // Empty
}

void ExynosCamera::stopPreview() {
    // Empty
}

bool ExynosCamera::previewEnabled() {
    return 0;
}

status_t ExynosCamera::storeMetaDataInBuffers(bool enable) {
    return 0;
}

status_t ExynosCamera::startRecording() {
    return 0;
}

void ExynosCamera::stopRecording() {
    // Empty
}

bool ExynosCamera::recordingEnabled() {
    return 0;
}

void ExynosCamera::releaseRecordingFrame(const void *opaque) {
    // Empty
}

status_t ExynosCamera::autoFocus() {
    return 0;
}

status_t ExynosCamera::cancelAutoFocus() {
    return 0;
}

status_t ExynosCamera::takePicture() {
    return 0;
}

status_t ExynosCamera::cancelPicture() {
    return 0;
}

status_t ExynosCamera::setParameters(const CameraParameters& params) {
    return 0;
}

CameraParameters ExynosCamera::getParameters() const {
    CameraParameters dummy_params;
    return dummy_params;
}

status_t ExynosCamera::sendCommand(int32_t command, int32_t arg1, int32_t arg2) {
    return 0;
}

void ExynosCamera::release() {
    // Empty
}

status_t ExynosCamera::dump(int fd) const {
    return 0;
}

int ExynosCamera::getCameraId() const {
    return 0;
}

}; // namespace android

