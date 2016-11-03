#include <fdfs_head.h>

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
