import { defineCollection, z } from 'astro:content';
import { glob } from 'astro/loaders';

// Each info.md file describes one program. Its sibling source file stays a
// normal .c/.cpp/.sh file in the programs directory.
const programs = defineCollection({
  loader: glob({ pattern: '**/info.md', base: './programs' }),
  schema: z.object({
    title: z.string().min(1),
    subject: z.string().default('Operating Systems'),
    part: z.enum(['A', 'B']).default('A'),
    category: z.string().optional(),
    language: z.enum(['c', 'cpp', 'bash', 'text']),
    source: z.string().min(1),
    order: z.number().int().default(999),
    tags: z.array(z.string()).default([])
  })
});

export const collections = { programs };
