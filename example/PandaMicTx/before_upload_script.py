import os
from SCons.Script import DefaultEnvironment

# 定义 ANSI 转义序列
GREEN = "\033[32m"  # 绿色
RESET = "\033[0m"   # 重置颜色

def before_upload(source, target, env):
    # 获取生成的固件路径
    # $BUILD_DIR：构建输出目录
    # $PROJECT_DIR：项目根目录
    # $SOURCE_DIR：源代码目录
    # $PIOENV：当前环境名称
    firmware_path = os.path.join(env.subst("$BUILD_DIR"), "firmware.bin")

    # 定义 NVS 分区文件和脚本路径
    partition_file = os.path.join(env.GetProjectOption("extra_script_default_envs_path"), "panda-mic.csv")
    nvs_script = os.path.join(env.GetProjectOption("extra_script_default_envs_path"), "nvs_partition_gen.py")
    nvs_size = env.GetProjectOption("extra_script_nvs_size")

    # 打印调试信息
    print(GREEN + "Executing NVS partition generation..." + RESET)
    print(GREEN + f"python {nvs_script} generate {partition_file} {firmware_path} {nvs_size}" + RESET)

    # 执行 NVS 分区生成命令
    command = f"python {nvs_script} generate {partition_file} {firmware_path} {nvs_size}"
    os.system(command)

    # 输出绿色文本
    print(GREEN + "NVS partition generation finished!" + RESET)


env = DefaultEnvironment()
# 添加构建后钩子
env.AddPreAction("upload", before_upload)
