#include <fdfs_head.h>

int op_fdfs_upload_file(const char * local_filename, ConnectionInfo * pTrackerServer, char * file_id)
{
    int retn = 0;
    int store_path_index = 0;
    char group_name[FDFS_GROUP_NAME_MAX_LEN];
    ConnectionInfo storageServer;
    memset(&storageServer, 0, sizeof(ConnectionInfo));
    *group_name = '\0';

    if (NULL == local_filename || NULL == pTrackerServer) {
        retn = -1;
        goto END;
    }

    ignore_signal_pipe();

    retn = tracker_query_storage_store(pTrackerServer, &storageServer, \
            group_name, &store_path_index);
    if (retn != 0) {
        retn = -1;
        goto END;
    }

    retn = storage_upload_by_filename1(pTrackerServer, &storageServer, store_path_index, local_filename, NULL, NULL, 0, group_name, file_id);
    if (0 != retn) {
        retn = -1;
        goto END;
    }


END:
    return retn;
}
