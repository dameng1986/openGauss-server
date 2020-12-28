/*
 * Copyright (c) 2020 Huawei Technologies Co.,Ltd.
 *
 * openGauss is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v2 for more details.
 * ---------------------------------------------------------------------------------------
 *
 * pg_hashbucket_fn.h
 *
 *
 * IDENTIFICATION
 *        src/include/catalog/pg_hashbucket_fn.h
 *
 * ---------------------------------------------------------------------------------------
 */

#ifndef PG_HASHBUCKET_FN_H
#define PG_HASHBUCKET_FN_H

extern Oid insertHashBucketEntry(oidvector *bucketlist, Oid bucketid);
extern Oid searchHashBucketByBucketid(oidvector *bucketlist, Oid bucketid);
extern text* searchMergeListByRelid(Oid reloid, bool *find, bool retresult = true);

extern oidvector *searchHashBucketByOid(Oid bucketOid);
extern List *relationGetBucketRelList(Relation rel, Partition part);
extern void BucketCacheInitialize(void);
extern void AtEOXact_BucketCache(bool isCommit);
extern void AtEOSubXact_BucketCache(bool isCommit, SubTransactionId mySubid, SubTransactionId parentSubid);
extern int64 execute_drop_bucketlist(Oid relOid1, Oid relOid2, bool isPart);
extern int64 execute_move_bucketlist(Oid relOid1, Oid relOid2, bool isPart);
extern void relation_swap_bucket(Oid r1, Oid r2);
#endif

