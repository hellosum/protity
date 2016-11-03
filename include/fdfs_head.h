#ifndef _FDFS_HEAD_H
#define _FDFS_HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fdfs_client.h>
#include <logger.h>

//上传文件
int op_fdfs_upload_file(const char * local_filename, ConnectionInfo * pTrackerServer, char * file_id);

int op_fdfs_file_info(FDFSFileInfo *file_info, const char * file_id);

int op_fdfs_client_init(ConnectionInfo **pTrackerServer, const char * conf_filename);

int op_fdfs_client_destroy(ConnectionInfo *pTrackerServer);

int op_fdfs_disconnect_server(ConnectionInfo *conn);

#endif
