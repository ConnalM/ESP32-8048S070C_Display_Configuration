Import("env")

# This script excludes problematic assembly files from compilation

def exclude_asm_files(env):
    # Get the current build flags
    build_flags = env.get("BUILD_FLAGS", [])
    
    # Add flags to ignore specific assembly files
    build_flags.append("-DLVGL_SKIP_ASSEMBLY=1")
    
    # Update the environment
    env.Replace(BUILD_FLAGS=build_flags)
    
    # Modify the build source filter to exclude assembly files
    src_filter = env.get("SRC_FILTER", [])
    src_filter.append("-<**/*.S>")
    src_filter.append("-<**/*.s>")
    env.Replace(SRC_FILTER=src_filter)

exclude_asm_files(env)
