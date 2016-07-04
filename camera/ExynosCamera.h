/*
**
** Copyright 2012, Samsung Electronics Co. LTD
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef EXYNOS_CAMERA_HW_IMPLEMENTATION_H
#define EXYNOS_CAMERA_HW_IMPLEMENTATION_H

#include <utils/threads.h>
#include <utils/RefBase.h>
#include <binder/MemoryBase.h>
#include <binder/MemoryHeapBase.h>
#include <hardware/camera.h>
#include <hardware/gralloc.h>
#include <camera/Camera.h>
#include <camera/CameraParameters.h>
#include <media/hardware/MetadataBufferType.h>

#include <fcntl.h>
#include <sys/mman.h>

namespace android {

class ExynosCamera {
public:
    ExynosCamera() {};
    ExynosCamera(int cameraId, camera_device_t *dev);
    virtual             ~ExynosCamera();

    status_t    setPreviewWindow(preview_stream_ops *w);
    void        setCallbacks(
                    camera_notify_callback notify_cb,
                    camera_data_callback data_cb,
                    camera_data_timestamp_callback data_cb_timestamp,
                    camera_request_memory get_memory,
                    void *user);

    void        enableMsgType(int32_t msgType);
    void        disableMsgType(int32_t msgType);
    bool        msgTypeEnabled(int32_t msgType);

    void        startPreview();
    void        stopPreview();
    bool        previewEnabled();

    status_t    storeMetaDataInBuffers(bool enable);

    status_t    startRecording();
    void        stopRecording();
    bool        recordingEnabled();
    void        releaseRecordingFrame(const void *opaque);

    status_t    autoFocus();
    status_t    cancelAutoFocus();

    status_t    takePicture();
    status_t    cancelPicture();

    status_t    setParameters(const CameraParameters& params);
    CameraParameters  getParameters() const;
    status_t    sendCommand(int32_t command, int32_t arg1, int32_t arg2);

    void        release();

    status_t    dump(int fd) const;

    int  getCameraId() const;
};

}; // namespace android

#endif
