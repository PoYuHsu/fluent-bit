/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Fluent Bit
 *  ==========
 *  Copyright (C) 2015-2018 Treasure Data Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef FLB_PIPE_H
#define FLB_PIPE_H

#ifdef _WIN32
#include <event.h>
#define flb_pipefd_t evutil_socket_t
#define flb_sockfd_t evutil_socket_t
#define flb_pipe_w(fd, buf, len) send(fd, buf, len, 0)
#define flb_pipe_r(fd, buf, len) recv(fd, buf, len, 0)
#else
#include <unistd.h>
#define flb_pipefd_t int
#define flb_sockfd_t int
#define flb_pipe_w(fd, buf, len) write(fd, buf, len)
#define flb_pipe_r(fd, buf, len) read(fd, buf, len)
#endif

int flb_pipe_create(flb_pipefd_t pipefd[2]);
void flb_pipe_destroy(flb_pipefd_t pipefd[2]);
int flb_pipe_close(flb_pipefd_t fd);
ssize_t flb_pipe_read_all(int fd, void *buf, size_t count);
ssize_t flb_pipe_write_all(int fd, void *buf, size_t count);

#endif
