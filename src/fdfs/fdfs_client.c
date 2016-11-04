/************************************************************************
 *  作者:       谢红星                                                  *
 *  日期:       2016/11/3                                               *
 *  描述:       该文件代码对客户端进行初始化，销毁客户端,断开与服务器   *
 *              的连接；                                                *
 ************************************************************************/

#include <fdfs_head.h>


/**********************************************************
 * 方法:    op_fdfs_client_init                           *
 * 参数:    pTrackerServer:   --    返回tracker的连接     *
 *          conf_filename:    --    配置文件              *
 * 返回:    retn               0    成功                  *
 *                             1    失败                  *
 *                                                        *
 **********************************************************/
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



/**********************************************************
 * 方法:    op_fdfs_client_destroy                        *
 * 参数:    ConnectionInfo   --    tracker的连接          *
 * 返回:    retn               0    成功                  *
 * 描述：   销毁客户端对tracker的连接；                   *
 **********************************************************/
int op_fdfs_client_destroy(ConnectionInfo *pTrackerServer)
{
    int retn = 0;

    tracker_disconnect_server_ex(pTrackerServer, true);
    fdfs_client_destroy();

    return retn;
}


/**********************************************************
 * 方法:    op_fdfs_disconnect_server                     *
 * 参数:    conn        tracker/storage的连接             *
 * 返回:    retn        0    成功                         *
 * 描述：   销毁客户端对tracker的连接；                   *
 **********************************************************/
int op_fdfs_disconnect_server(ConnectionInfo *conn)
{
    int retn = 0;

    tracker_disconnect_server_ex(conn, true);

    return retn;
}


