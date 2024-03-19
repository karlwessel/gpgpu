using oneAPI

exponent = 20
if length(ARGS) > 0
    exponent = parse(Int, ARGS[1])
end
println(exponent)
N = 2^exponent

a = oneArray(ones(Float32, N))
b = oneArray(ones(Float32, N)*2)

b .+= 2 .* a

println(maximum(b .- 4))
