Examples using julias oneAPI wrapper.

# Setup
Instantiate the project environment:
1. Start Julia in the `julia` folder.
  `julia --project`
2. Switch to package manager mode by typing `]`
3. Instantiate the environment
  `instantiate`

Per default oneAPI.jl brings its own oneAPI libraries. In case they don't work
one can use the system libraries by calling `oneAPI.jl`s `res/local.jl` script.
See `oneAPI.jl` [documentation](https://github.com/JuliaGPU/oneAPI.jl) for
details.

# Execute examples
In the `julia` folder run
`julia --project src/saxpy.jl`.
