/*
 * Copyright (C) 2010-2020 Arm Limited or its affiliates. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* ----------------------------------------------------------------------
 * Project:      CMSIS NN Library
 * Title:        arm_nn_accumulate_q7_to_q15.c
 * Description:  Accumulate q7 vector into q15 one.
 *
 * $Date:        09. October 2020
 * $Revision:    V.1.0.2
 *
 * pSrc Processor:  Cortex-M CPUs
 *
 * -------------------------------------------------------------------- */

#include "edge-impulse-sdk/CMSIS/NN/Include/arm_nnfunctions.h"
#include "edge-impulse-sdk/CMSIS/NN/Include/arm_nnsupportfunctions.h"

/**
 * @ingroup groupSupport
 */

/**
 * @addtogroup NNBasicMath
 * @{
 */

/**
   * @brief definition to pack two 16 bit values.
   */
  #define __PKHBT(ARG1, ARG2, ARG3) ( (((int32_t)(ARG1) <<    0) & (int32_t)0x0000FFFF) | \
                                      (((int32_t)(ARG2) << ARG3) & (int32_t)0xFFFF0000)  )
  #define __PKHTB(ARG1, ARG2, ARG3) ( (((int32_t)(ARG1) <<    0) & (int32_t)0xFFFF0000) | \
                                      (((int32_t)(ARG2) >> ARG3) & (int32_t)0x0000FFFF)  )


  /*
   * @brief C custom defined SADD16 (by Edge Impulse)
   */
  __STATIC_FORCEINLINE uint32_t __SADD16(
  uint32_t x,
  uint32_t y)
  {
    q31_t r, s;

    r = (((((q31_t)x << 16) >> 16) + (((q31_t)y << 16) >> 16))) & (int32_t)0x0000FFFF;
    s = (((((q31_t)x      ) >> 16) + (((q31_t)y      ) >> 16))) & (int32_t)0x0000FFFF;

    return ((uint32_t)((s << 16) | (r      )));
  }

void arm_nn_accumulate_q7_to_q15(q15_t *pDst, const q7_t *pSrc, uint32_t length)
{
    q15_t *pCnt = pDst;
    const q7_t *pV = pSrc;
    q31_t v1, v2, vo1, vo2;
    int32_t cnt = length >> 2;
    q31_t in;

    while (cnt > 0l)
    {
        q31_t value = arm_nn_read_q7x4_ia(&pV);
        v1 = __SXTB16(__ROR((uint32_t)value, 8));
        v2 = __SXTB16(value);
#ifndef ARM_MATH_BIG_ENDIAN
        vo2 = (q31_t)__PKHTB(v1, v2, 16);
        vo1 = (q31_t)__PKHBT(v2, v1, 16);
#else
        vo1 = (q31_t)__PKHTB(v1, v2, 16);
        vo2 = (q31_t)__PKHBT(v2, v1, 16);
#endif

        in = arm_nn_read_q15x2(pCnt);
        arm_nn_write_q15x2_ia(&pCnt, __QADD16(vo1, in));

        in = arm_nn_read_q15x2(pCnt);
        arm_nn_write_q15x2_ia(&pCnt, __QADD16(vo2, in));

        cnt--;
    }
    cnt = length & 0x3;
    while (cnt > 0l)
    {
        *pCnt++ += *pV++;
        cnt--;
    }
}

/**
 * @} end of NNBasicMath group
 */
