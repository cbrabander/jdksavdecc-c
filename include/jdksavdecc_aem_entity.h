#pragma once
#ifndef JDKSAVDECC_AEM_ENTITY_H
#define JDKSAVDECC_AEM_ENTITY_H

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
#include "jdksavdecc_adp.h"
#include "jdksavdecc_aecp_aem.h"
#include "jdksavdecc_aem_command.h"
#include "jdksavdecc_aem_descriptor.h"

#ifdef __cplusplus
extern "C" {
#endif

struct jdksavdecc_entity_info
{
    struct jdksavdecc_adpdu advertising_info;
    void (*send_advertise_on_all_interfaces)(struct jdksavdecc_entity_info *);
    uint16_t num_interfaces;
    struct jdksavdecc_adp_advertising_interface_state_machine *interfaces;
    // TODO
};

/// @todo aem_entity_state_machine
struct jdksavdecc_aem_entity_state_machine
{
    uint32_t tag;
    void *additional;

    struct jdksavdecc_frame_sender *frame_sender;

    void (*destroy)( struct jdksavdecc_aem_entity_state_machine * );
    void (*tick)( struct jdksavdecc_aem_entity_state_machine *self, jdksavdecc_timestamp_in_microseconds timestamp );
    ssize_t (*rx_frame)( struct jdksavdecc_aem_entity_state_machine *self, struct jdksavdecc_frame *rx_frame, size_t pos );
};
#ifdef __cplusplus
}
#endif

#endif

