#include <vulkan/vulkan.h>

class GpuInfo
{
public:
    explicit GpuInfo();
    virtual ~GpuInfo();

    // vulkan physical device
    VkPhysicalDevice physical_device() const;

    // memory properties
    const VkPhysicalDeviceMemoryProperties& physical_device_memory_properties() const;

    // info
    uint32_t api_version() const;
    uint32_t driver_version() const;
    uint32_t vendor_id() const;
    uint32_t device_id() const;
    const char* device_name() const;
    uint8_t* pipeline_cache_uuid() const;

    // 0 = discrete gpu
    // 1 = integrated gpu
    // 2 = virtual gpu
    // 3 = cpu
    int type() const;

    // hardware limit
    uint32_t max_shared_memory_size() const;
    uint32_t max_workgroup_count_x() const;
    uint32_t max_workgroup_count_y() const;
    uint32_t max_workgroup_count_z() const;
    uint32_t max_workgroup_invocations() const;
    uint32_t max_workgroup_size_x() const;
    uint32_t max_workgroup_size_y() const;
    uint32_t max_workgroup_size_z() const;
    size_t memory_map_alignment() const;
    size_t buffer_offset_alignment() const;
    size_t non_coherent_atom_size() const;
    size_t buffer_image_granularity() const;
    uint32_t max_image_dimension_1d() const;
    uint32_t max_image_dimension_2d() const;
    uint32_t max_image_dimension_3d() const;
    float timestamp_period() const;

    // runtime
    uint32_t compute_queue_family_index() const;
    uint32_t graphics_queue_family_index() const;
    uint32_t transfer_queue_family_index() const;

    uint32_t compute_queue_count() const;
    uint32_t graphics_queue_count() const;
    uint32_t transfer_queue_count() const;

    // property
    bool unified_compute_transfer_queue() const;

    // subgroup
    uint32_t subgroup_size() const;
    bool support_subgroup_basic() const;
    bool support_subgroup_vote() const;
    bool support_subgroup_ballot() const;
    bool support_subgroup_shuffle() const;

    // bug is not feature
    bool bug_storage_buffer_no_l1() const;
    bool bug_corrupted_online_pipeline_cache() const;
    bool bug_buffer_image_load_zero() const;

    // but sometimes bug is a feature
    bool bug_implicit_fp16_arithmetic() const;

    // fp16 and int8 feature
    bool support_fp16_packed() const;
    bool support_fp16_storage() const;
    bool support_fp16_arithmetic() const;
    bool support_int8_packed() const;
    bool support_int8_storage() const;
    bool support_int8_arithmetic() const;

    // ycbcr conversion feature
    bool support_ycbcr_conversion() const;

    // extension capability
    int support_VK_KHR_8bit_storage() const;
    int support_VK_KHR_16bit_storage() const;
    int support_VK_KHR_bind_memory2() const;
    int support_VK_KHR_create_renderpass2() const;
    int support_VK_KHR_dedicated_allocation() const;
    int support_VK_KHR_descriptor_update_template() const;
    int support_VK_KHR_external_memory() const;
    int support_VK_KHR_get_memory_requirements2() const;
    int support_VK_KHR_maintenance1() const;
    int support_VK_KHR_maintenance2() const;
    int support_VK_KHR_maintenance3() const;
    int support_VK_KHR_multiview() const;
    int support_VK_KHR_push_descriptor() const;
    int support_VK_KHR_sampler_ycbcr_conversion() const;
    int support_VK_KHR_shader_float16_int8() const;
    int support_VK_KHR_shader_float_controls() const;
    int support_VK_KHR_storage_buffer_storage_class() const;
    int support_VK_KHR_swapchain() const;
    int support_VK_EXT_descriptor_indexing() const;
    int support_VK_EXT_memory_budget() const;
    int support_VK_EXT_queue_family_foreign() const;
#if __ANDROID_API__ >= 26
    int support_VK_ANDROID_external_memory_android_hardware_buffer() const;
#endif // __ANDROID_API__ >= 26

private:
    GpuInfo(const GpuInfo&);
    GpuInfo& operator=(const GpuInfo&);

private:
    friend int create_gpu_instance();
    // GpuInfoPrivate* const d;
};