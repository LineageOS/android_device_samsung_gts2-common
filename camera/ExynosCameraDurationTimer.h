/*
 * Copyright (C) 2014 The CyanogenMod Project
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

#ifndef EXYNOS_CAMERA_DURATION_TIMER_H
#define EXYNOS_CAMERA_DURATION_TIMER_H

class DurationTimer {
public:
    DurationTimer() {}
    ~DurationTimer() {}
    void start();
    void stop();
    long long durationUsecs() const;
    static long long subtractTimevals(const struct timeval* ptv1,
        const struct timeval* ptv2);
    static void addToTimeval(struct timeval* ptv, long usec);
private:
    struct timeval mStartWhen;
    struct timeval mStopWhen;
};

#endif
