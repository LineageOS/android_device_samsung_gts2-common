/*
 * Copyright (c) 2015-2016 Andreas Schneider <asn@cryptomilk.org>
 * Copyright (C) 2013-2016 The CyanogenMod Project
 *               Daniel Hillenbrand <codeworkx@cyanogenmod.com>
 *               Guillaume "XpLoDWilD" Lesniak <xplodgui@gmail.com>
 *               Christopher N. Hesse <raymanfx@gmail.org>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _RIL_INTERFACE_H_
#define _RIL_INTERFACE_H_

#include <telephony/ril.h>
#include "secril-client.h"

struct ril_handle
{
    // HRilClient --> Ril_Client*
    HRilClient client;
    int volume_steps_max;
};


/* Function prototypes */
int ril_open(struct ril_handle *ril);

int ril_close(struct ril_handle *ril);

int ril_set_call_volume(struct ril_handle *ril,
                        enum _SoundType sound_type,
                        float volume);

int ril_set_call_audio_path(struct ril_handle *ril,
                            enum _AudioPath path);

int ril_set_call_clock_sync(struct ril_handle *ril,
                            enum _SoundClockCondition condition);

int ril_set_mute(struct ril_handle *ril, enum _MuteCondition condition);

int ril_set_two_mic_control(struct ril_handle *ril,
                            enum __TwoMicSolDevice device,
                            enum __TwoMicSolReport report);

void ril_register_set_callback_data(struct audio_device *adev);

#endif
