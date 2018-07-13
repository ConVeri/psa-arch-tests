/** @file
 * Copyright (c) 2018, Arm Limited or its affiliates. All rights reserved.
 * SPDX-License-Identifier : Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
**/

#include "uart_cmsdk.h"
#include "timer_cmsdk.h"
#include "wd_cmsdk.h"
#include "pal_dpm_fvp.h"
#include "nvram.h"
#include "pal_database.h"

void *pal_get_target_cfg_start(void)
{
    return (void *)database;
}

void pal_NVIC_EnableIRQ(uint32_t intr_num)
{
    NVIC_EnableIRQ(intr_num);
}

void pal_NVIC_DisableIRQ(uint32_t intr_num)
{
    NVIC_DisableIRQ(intr_num);
}

uint32_t pal_NVIC_ClearTargetState(uint32_t intr_num)
{
    return NVIC_ClearTargetState(intr_num);
}

uint32_t pal_NVIC_SetTargetState(uint32_t intr_num)
{
    return NVIC_SetTargetState(intr_num);
}

void pal_NVIC_SetPriority(uint32_t intr_num, uint32_t priority)
{
    return NVIC_SetPriority(intr_num, priority);
}

uint32_t pal_NVIC_GetPriority(uint32_t intr_num)
{
    return NVIC_GetPriority(intr_num);
}

void pal_NVIC_SetPendingIRQ(uint32_t intr_num)
{
    NVIC_SetPendingIRQ(intr_num);
}

void pal_NVIC_ClearPendingIRQ(uint32_t intr_num)
{
    NVIC_ClearPendingIRQ(intr_num);
}

uint32_t pal_NVIC_GetPendingIRQ(uint32_t intr_num)
{
    return NVIC_GetPendingIRQ(intr_num);
}

uint32_t pal_NVIC_GetActive(uint32_t intr_num)
{
    return NVIC_GetActive(intr_num);
}

void pal_uart_init(addr_t base_addr)
{
    uart_init(base_addr);
}

void pal_uart_tx(uint8_t data)
{
    uart_putc(data);
}

void pal_i2c_init(void)
{
    return;
}

int pal_i2c_read(uint32_t slv_addr, uint8_t *rd_data, uint32_t len)
{
    return 0xFF;
}

int pal_i2c_write(uint32_t slv_addr, uint8_t *wr_data, uint32_t len)
{
    return 0xFF;
}

void pal_spi_init(void)
{
   return;
}

int pal_spi_read(uint32_t addr, uint8_t *data, uint32_t len)
{
    return 0xFF;
}

int pal_spi_write(uint32_t addr, uint8_t *data, uint32_t len)
{
    return 0xFF;
}

int pal_timer_init (addr_t base_addr, uint32_t time_us, uint32_t timer_tick_us)
{
    return timer_cmsdk_init(base_addr, time_us, timer_tick_us);
}

int pal_timer_enable (addr_t base_addr)
{
    return timer_cmsdk_enable(base_addr);
}

int pal_timer_disable (addr_t base_addr)
{
    return timer_cmsdk_disable(base_addr);
}

int pal_timer_interrupt_clear (addr_t base_addr)
{
    return timer_cmsdk_interrupt_clear(base_addr);
}

int pal_crypto_aes_generate_key(uint8_t *key, uint32_t size)
{
    return 0xFF;
}

int pal_crypto_compute_hash(unsigned char *input, size_t ilen, unsigned char *output, int algo)
{
    return 0xFF;
}

int pal_wd_timer_init (addr_t base_addr, uint32_t time_us, uint32_t timer_tick_us)
{
    return wd_cmsdk_init(base_addr, time_us, timer_tick_us);
}

int pal_wd_timer_enable (addr_t base_addr)
{
    return wd_cmsdk_enable(base_addr);
}

int pal_wd_timer_disable (addr_t base_addr)
{
    return wd_cmsdk_disable(base_addr);
}

int pal_is_wd_timer_enabled (addr_t base_addr)
{
    return wd_cmsdk_is_enabled(base_addr);
}

int pal_dpm_set_access_ns_only(uint32_t index, bool_t access_ns)
{
    return pal_dpm_fvp_set_access_ns_only(index, access_ns);
}

int pal_mpc_configure_mem_to_nonsecure (addr_t start_addr,addr_t end_addr)
{
    return -1;
}

int pal_mpc_configure_mem_to_secure (addr_t start_addr,addr_t end_addr)
{
    return -1;
}

void pal_crypto_init(addr_t crypto_base_addr)
{
    return;
}

int pal_fuse_read(addr_t addr, uint32_t *data, size_t size)
{
    return -1;
}

int pal_fuse_write(addr_t addr, uint32_t *data, size_t size)
{
    return -1;
}

int pal_fuse_count_zeros_in_rotpk(uint32_t *zero_cnt)
{
    return 0;
}

void pal_fuse_count_zeros(uint32_t value, uint32_t *zero_cnt)
{
   return;
}

int pal_nvram_write(addr_t base, uint32_t offset, void *buffer, int size)
{
    return nvram_write(base, offset, buffer, size);
}

int pal_nvram_read(addr_t base, uint32_t offset, void *buffer, int size)
{
    return nvram_read(base, offset, buffer, size);
}

void pal_system_warm_reset(void)
{
    NVIC_SystemReset();
}

void pal_system_cold_reset(void)
{
    return;
}

int pal_is_cold_reset(void)
{
    return 0;
}

int pal_is_warm_reset(void)
{
    /* Simulating as if we get this information from trustd world */
    int x = *(uint32_t*)0x50000000UL;
    return x;
}

int pal_fuse_get_lcs(uint32_t *pLcs)
{
    return -1;
}

int pal_rtc_init(addr_t base_addr)
{
    return -1;
}

int pal_is_rtc_trustable(addr_t base_addr)
{
    return 0;
}

int pal_is_rtc_synced_to_server(addr_t base_addr)
{
    return 0;
}

int pal_crypto_validate_certificate(uint32_t certificate_base_addr, uint32_t public_key_addr, uint32_t certificate_size, uint32_t public_key_size)
{
    return -1;
}

int pal_crypto_get_uniqueID_from_certificate(uint32_t certificate_base_addr, uint32_t public_key_addr, uint32_t certificate_size, uint32_t public_key_size)
{
    return -1;
}

int pal_crypto_get_dpm_from_key(uint32_t public_key_addr, uint32_t public_key_size, uint32_t *dpm_field)
{
    return -1;
}

int pal_crypto_get_dpm_from_certificate(uint32_t certificate_base_addr, uint32_t certificate_size, uint32_t *dpm_field)
{
    return -1;
}

int pal_firmware_version_update(uint32_t instance, uint32_t firmware_version_type, uint32_t fw_ver_cnt)
{
    return -1;
}

int pal_firmware_version_read(uint32_t instance, uint32_t firmware_version_type)
{
    return -1;
}
