Import("env")

def exclude_asm_files(env):
    print("Applying custom build configuration to exclude assembly files...")
    
    # Get the current build flags
    build_flags = env.get("BUILD_FLAGS", [])
    
    # Add flags to disable assembly optimizations
    build_flags.extend([
        "-DLV_USE_DRAW_SW_ASM=0",
        "-DLV_USE_DRAW_SW_HELIUM=0",
        "-DLV_USE_DRAW_SW_NEON=0",
        "-DLV_USE_VECTOR_GRAPHIC=0"
    ])
    
    # Update the environment
    env.Replace(BUILD_FLAGS=build_flags)
    
    # Modify the build source filter to exclude assembly files
    env.Append(SRC_FILTER=[
        "-<**/*.S>",
        "-<**/*.s>"
    ])
    
    # Create a hook to ignore assembly files during compilation
    def process_ignore_patterns(node):
        name = node.get_path()
        if name.endswith(".S") or name.endswith(".s"):
            print(f"Excluding assembly file: {name}")
            return None
        return node
    
    # Apply the hook
    env.AddBuildMiddleware(process_ignore_patterns)
    
    print("Custom build configuration applied successfully.")

# Apply the custom build configuration
exclude_asm_files(env)
