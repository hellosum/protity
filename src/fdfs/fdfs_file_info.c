/************************************************************************
 *  作者:       谢红星                                                  *
 *  日期:       2016/11/3                                               *
 *  描述:       通过文件id获得文件信息；                                *
 ************************************************************************/

#include <fdfs_head.h>

/************************************************************************
 *  方法:       op_fdfs_file_info                                       *
 *  参数:       file_info               返回的文件信息                  *
 *              file_id                 文件id                          *
 *  返回：      0                       成功                            *
 *              -1                      失败                            *
 *  描述:       通过文件id获得文件信息；                                *
 ************************************************************************/

int op_fdfs_file_info(FDFSFileInfo *file_info, const char * file_id)
{
    int retn = 0;
    if (NULL == file_info || NULL == file_id) {
        retn = -1;
        goto END;
    }

    ignore_signal_pipe();

    retn = fdfs_get_file_info_ex1(file_id, true, file_info);    
    if (retn != 0) {
        retn = -1;
        goto END;
    }

END:
    return retn;
}
