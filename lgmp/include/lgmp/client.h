/*
LGMP - Looking Glass Memory Protocol
Copyright (C) 2020 Geoffrey McRae <geoff@hostfission.com>
https://looking-glass.hostfission.com

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef LGMP_CLIENT_H
#define LGMP_CLIENT_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "lgmp.h"
#include "status.h"

#ifdef __cplusplus
extern "C" {
#endif

LGMP_STATUS lgmpClientInit(void * mem, const size_t size, PLGMPClient * result);
void        lgmpClientFree(PLGMPClient * client);
bool        lgmpClientSessionValid(PLGMPClient client);

LGMP_STATUS lgmpClientSubscribe(PLGMPClient client, uint32_t type, PLGMPQueue * result);
LGMP_STATUS lgmpClientUnsubscribe(PLGMPQueue * result);

typedef struct
{
  uint32_t   type;
  uint32_t   size;
  void     * mem;
}
LGMPMessage, * PLGMPMessage;

LGMP_STATUS lgmpClientProcess(PLGMPQueue queue, PLGMPMessage result);
LGMP_STATUS lgmpClientMessageDone(PLGMPQueue queue);

#ifdef __cplusplus
}
#endif

#endif