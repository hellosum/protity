#include <fdfs_head.h>

int main(int argc, char * argv[])
{
    if (argc < 3)
        return -1;

    ConnectionInfo * pTrackerSvr = NULL;
    char file_id[1024] = {0};
    char * local_file = argv[2];

    op_fdfs_client_init(&pTrackerSvr, argv[1]);

    op_fdfs_upload_file(local_file, pTrackerSvr, file_id);
    printf("%s\n", file_id);
    op_fdfs_client_destroy(pTrackerSvr);

    return 0;
}
