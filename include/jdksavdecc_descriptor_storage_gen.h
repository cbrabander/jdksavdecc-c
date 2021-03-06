#pragma once
#ifndef JDKSAVDECC_DESCRIPTOR_STORAGE_GEN_H
#define JDKSAVDECC_DESCRIPTOR_STORAGE_GEN_H

/*
  Copyright (c) 2013, J.D. Koftinoff Software, Ltd.
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.

   3. Neither the name of J.D. Koftinoff Software, Ltd. nor the names of its
      contributors may be used to endorse or promote products derived from
      this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.
*/

#include "jdksavdecc_world.h"
#include "jdksavdecc_descriptor_storage.h"

#ifdef __cplusplus
extern "C" {
#endif


/** \addtogroup descriptor_storage_gen Descriptor Storage Generator
 *  @todo descriptor_storage_gen
*/
/*@{*/

struct jdksavdecc_descriptor_storage_gen
{
    void (*destroy)( struct jdksavdecc_descriptor_storage_gen *self );
    void (*error)( struct jdksavdecc_descriptor_storage_gen *self, int code );

    uint8_t *buffer;
    size_t buffer_size;
    size_t buffer_pos;

    uint8_t *current_descriptor_list_chunk;
    uint8_t *current_configuration_chunk;
};

void jdksavdecc_descriptor_storage_gen_init(
        struct jdksavdecc_descriptor_storage_gen *self,
        uint8_t *buffer,
        size_t buffer_size
        );

void jdksavdecc_descriptor_storage_gen_destroy(
        struct jdksavdecc_descriptor_storage_gen *self
        );

void jdksavdecc_descriptor_storage_gen_finish(
        struct jdksavdecc_descriptor_storage_gen *self
        );

void jdksavdecc_descriptor_storage_gen_add_configuration(
        struct jdksavdecc_descriptor_storage_gen *self
        );

void jdksavdecc_descriptor_storage_gen_finish_configuration(
        struct jdksavdecc_descriptor_storage_gen *self
        );

void jdksavdecc_descriptor_storage_gen_add_descriptor_list(
        struct jdksavdecc_descriptor_storage_gen *self,
        uint16_t descriptor_type
        );

void jdksavdecc_descriptor_storage_gen_finish_descriptor_list(
        struct jdksavdecc_descriptor_storage_gen *self
        );

void jdksavdecc_descriptor_storage_gen_add_descriptor(
        struct jdksavdecc_descriptor_storage_gen *self,
        struct jdksavdecc_descriptor const *descriptor,
        uint16_t descriptor_len
        );

int jdksavdecc_descriptor_storage_gen_export_binary(
        uint8_t const *buffer,
        size_t buffer_len,
        const char *fname
        );

int jdksavdecc_descriptor_storage_gen_export_c(
        uint8_t const *buffer,
        size_t buffer_len,
        const char *fname_c,
        const char *fname_h
        );

/*@}*/

#ifdef __cplusplus
}
#endif

#endif

