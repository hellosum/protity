#include <fdfs_head.h>


int op_fdfs_client_init(ConnectionInfo **pTrackerServer, const char * conf_filename)
{
    int retn = 0;
    if (NULL == conf_filename) {
        retn = -1;
        goto END;
    }

    retn = fdfs_client_init(conf_filename);
    if (retn != 0) {
        retn = -1;
        goto END;
    }
    
    *pTrackerServer = tracker_get_connection();
    if (NULL == *pTrackerServer) {
        fdfs_client_destroy();
        retn = -1;
        goto END;
    }

END:
    return retn;
}

int op_fdfs_client_destroy(ConnectionInfo *pTrackerServer)
{
    int retn = 0;

    tracker_disconnect_server_ex(pTrackerServer, true);
    fdfs_client_destroy();

    return retn;
}

int op_fdfs_disconnect_server(ConnectionInfo *conn)
{
    int retn = 0;

    tracker_disconnect_server_ex(conn, true);

    return retn;
}










