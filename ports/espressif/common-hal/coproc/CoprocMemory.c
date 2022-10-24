/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2022 microDev
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "shared-bindings/coproc/CoprocMemory.h"

uint32_t common_hal_coproc_memory_get_length(coproc_memory_obj_t *self) {
    return self->len;
}

bool common_hal_coproc_memory_set_bytes(coproc_memory_obj_t *self,
    uint32_t start_index, const uint8_t *values, uint32_t len) {

    if (start_index + len > self->len) {
        return false;
    }

    memcpy((uint8_t *)(self->address + start_index), values, len);
    return true;
}

void common_hal_coproc_memory_get_bytes(coproc_memory_obj_t *self,
    uint32_t start_index, uint8_t *values, uint32_t len) {

    if (start_index + len > self->len) {
        return;
    }

    memcpy(values, (uint8_t *)(self->address + start_index), len);
}
