
// make arays into pointers
void bfs (int a, int *b) {


    int nbyn = a*a;
    int copy_posarray[nbyn];
    int path_tracker[nbyn];
    int target_pos =0;
    int start_pos = 0;

    for (int i = 0; i < (nbyn); i++) {
        if (b[i] == 2) {
            start_pos++;
            *path_tracker = i;
            *(copy_posarray + i) = 2;

        }else{
            *(copy_posarray + i) = 1;
        }
    }

    while (start_pos - target_pos > 0) {
        //Up
        if ((*(path_tracker + target_pos) / a) != 0) {
            int ucoord = ((*(path_tracker + target_pos) / a) - 1)*a + (*(path_tracker + target_pos) % a);

            if (*(copy_posarray + ucoord) == 1) {
                if (*(b + ucoord) == 1) {
                    *(path_tracker + start_pos) = ucoord;
                    *(copy_posarray + ucoord) = *(path_tracker + target_pos);
                    start_pos++;
                }
                if (*(b+ ucoord) == 3) {
                    break;
                }
            }
        }
        //Down
        if ((*(path_tracker + target_pos) / a) != a - 1) {
            int dcoord = ((*(path_tracker + target_pos) / a) + 1)*a + (*(path_tracker + target_pos) % a);
            if (*(copy_posarray + dcoord) == 1) {
                if (*(b + dcoord) == 1) {
                    *(path_tracker + start_pos) = dcoord;
                    copy_posarray[dcoord] = path_tracker[target_pos];
                    start_pos++;
                }
                if (*(b+ dcoord) == 3) {
                    break;
                }
            }
        }

        // Left
        if ((path_tracker[target_pos] % a) != 0) {
            int lcoord = (path_tracker[target_pos]) + ((path_tracker[target_pos] % a) - 1);

            if (copy_posarray[lcoord] == 1) {
                if (b[lcoord] == 1) {
                    path_tracker[start_pos] = lcoord;
                    copy_posarray[lcoord] = path_tracker[target_pos];
                    start_pos++;
                }

                if (*(b+ lcoord) == 3) {
                    break;
                }
            }
        }

        // Right
        if ((path_tracker[target_pos] % a) != a - 1) {
            int rcoord = (path_tracker[target_pos]) + ((path_tracker[target_pos] % a) + 1);

            if (copy_posarray[rcoord] == 1) {
                if (b[rcoord] == 1) {
                    path_tracker[start_pos] = rcoord;
                    copy_posarray[rcoord] = path_tracker[target_pos];
                    start_pos++;
                }
                if (*(b+ rcoord) == 3) {
                    break;
                }
            }
        }

        target_pos++;
    }

    target_pos = *(path_tracker + target_pos);
    while(*(copy_posarray + target_pos) != 2) {
        *(b + target_pos) = 4;
        target_pos = *(copy_posarray + target_pos);
    }

}