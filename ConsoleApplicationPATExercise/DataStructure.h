#pragma once
//----here define link list for b-1004---

typedef struct stuInfo {
	char stu_name_c[11];
	char stu_number_c[11];
	unsigned stu_score_i;
	stuInfo *next_stu_info_pt;
}stu_info_1004, *stu_info_1004_pt;