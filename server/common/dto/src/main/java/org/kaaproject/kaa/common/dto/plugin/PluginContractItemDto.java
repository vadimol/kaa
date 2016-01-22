/*
 * Copyright 2015-2016 CyberVision, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package org.kaaproject.kaa.common.dto.plugin;

import java.io.Serializable;

public class PluginContractItemDto implements Serializable {

    private static final long serialVersionUID = 4627191000807507161L;

    private String id;
    private String configSchema;
    private ContractItemDto contractItem;

    public PluginContractItemDto() {
    }

    public PluginContractItemDto(String configSchema, ContractItemDto contractItem) {
        this.configSchema = configSchema;
        this.contractItem = contractItem;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getConfigSchema() {
        return configSchema;
    }

    public void setConfigSchema(String configSchema) {
        this.configSchema = configSchema;
    }

    public ContractItemDto getContractItem() {
        return contractItem;
    }

    public void setContractItem(ContractItemDto contractItem) {
        this.contractItem = contractItem;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof PluginContractItemDto)) {
            return false;
        }

        PluginContractItemDto that = (PluginContractItemDto) o;

        if (configSchema != null ? !configSchema.equals(that.configSchema) : that.configSchema != null) {
            return false;
        }
        if (contractItem != null ? !contractItem.equals(that.contractItem) : that.contractItem != null) {
            return false;
        }

        return true;
    }

    @Override
    public int hashCode() {
        int result = configSchema != null ? configSchema.hashCode() : 0;
        result = 31 * result + (contractItem != null ? contractItem.hashCode() : 0);
        return result;
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("PluginContractItemDto{");
        sb.append("id='").append(id).append('\'');
        sb.append(", configSchema='").append(configSchema).append('\'');
        sb.append(", contractItem=").append(contractItem);
        sb.append('}');
        return sb.toString();
    }
}
